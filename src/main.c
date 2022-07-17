#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cJSON.h"

#define CHECK_VAL_STRUCT(val) \
  if((val)==NULL) { \
    fprintf(stderr, "Failed to create value struct\n"); \
    exit(-1); \
  }

int main() {

  cJSON *val = NULL;
  cJSON *arrayval = NULL;

  cJSON *monitor = cJSON_CreateObject();
  if(monitor==NULL) {fprintf(stderr, "Failed to create monitor\n"); exit(-1);}

  val = cJSON_CreateNumber( 15 );
  CHECK_VAL_STRUCT(val)
  cJSON_AddItemToObject(monitor, "frame_id", val);

  val = cJSON_CreateString( "DCT_DCT" );
  CHECK_VAL_STRUCT(val)
  cJSON_AddItemToObject(monitor, "tx_type", val);

  double *pel_vals = (double*)calloc(sizeof(double), 8*8);

  srand((unsigned)time(NULL));
  for (int i=0; i < 8*8; i++) {
    pel_vals[i] = (double)rand() / RAND_MAX;
  }


  arrayval = cJSON_CreateDoubleArray(pel_vals, 8*8);
  CHECK_VAL_STRUCT(arrayval)
  cJSON_AddItemToObject(monitor, "orig", arrayval);

  const char *string = cJSON_PrintUnformatted(monitor);
  if(string==NULL) {fprintf(stderr, "Failed to parse json dict\n"); exit(-1);}

  FILE *fp = fopen( "test.json", "ab" );
  if(fp==NULL) {fprintf(stderr, "Failed to open file\n"); exit(-1);}

  fputs( string, fp );
  fputs( "\n", fp );

  fclose(fp);

  cJSON_Delete(monitor);
  free(pel_vals);
  free(string);

  return 0;
}