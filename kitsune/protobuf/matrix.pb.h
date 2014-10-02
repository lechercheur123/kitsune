/* Automatically generated nanopb header */
/* Generated by nanopb-0.2.9 at Wed Oct  1 17:15:00 2014. */

#ifndef _PB_MATRIX_PB_H_
#define _PB_MATRIX_PB_H_
#include <pb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _Matrix_DataType {
    Matrix_DataType_FLOAT = 0,
    Matrix_DataType_INT = 1
} Matrix_DataType;

/* Struct definitions */
typedef struct _Matrix {
    pb_callback_t id;
    int32_t rows;
    int32_t cols;
    Matrix_DataType datatype;
    pb_callback_t idata;
    pb_callback_t fdata;
    int64_t time1;
    int64_t time2;
    pb_callback_t tags;
    pb_callback_t source;
} Matrix;

typedef struct _MatrixClientMessage {
    pb_callback_t mac;
    bool has_unix_time;
    int32_t unix_time;
    bool has_matrix_payload;
    Matrix matrix_payload;
    pb_callback_t matrix_list;
} MatrixClientMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define MatrixClientMessage_init_default         {{{NULL}, NULL}, false, 0, false, Matrix_init_default, {{NULL}, NULL}}
#define Matrix_init_default                      {{{NULL}, NULL}, 0, 0, (Matrix_DataType)0, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, {{NULL}, NULL}, {{NULL}, NULL}}
#define MatrixClientMessage_init_zero            {{{NULL}, NULL}, false, 0, false, Matrix_init_zero, {{NULL}, NULL}}
#define Matrix_init_zero                         {{{NULL}, NULL}, 0, 0, (Matrix_DataType)0, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, {{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define Matrix_id_tag                            1
#define Matrix_rows_tag                          2
#define Matrix_cols_tag                          3
#define Matrix_datatype_tag                      4
#define Matrix_idata_tag                         5
#define Matrix_fdata_tag                         6
#define Matrix_time1_tag                         7
#define Matrix_time2_tag                         8
#define Matrix_tags_tag                          9
#define Matrix_source_tag                        10
#define MatrixClientMessage_mac_tag              1
#define MatrixClientMessage_unix_time_tag        2
#define MatrixClientMessage_matrix_payload_tag   3
#define MatrixClientMessage_matrix_list_tag      4

/* Struct field encoding specification for nanopb */
extern const pb_field_t MatrixClientMessage_fields[5];
extern const pb_field_t Matrix_fields[11];

/* Maximum encoded size of messages (where known) */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
