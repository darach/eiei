/*
 * Copyright (c) Darach Ennis - 2011. All Rights Reserved.
 * 
 * The contents of this file are subject to the Erlang Public License,
 * Version 1.1, (the "License"); you may not use this file except in
 * compliance with the License. You should have received a copy of the
 * Erlang Public License along with this software. If not, it can be
 * retrieved online at http://www.erlang.org/.
 * 
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 * 
 */


#ifndef __EIEI_
#define __EIEI_

#include "ei.h"

#ifdef __cplusplus
extern "C" {
#endif

int ei_x_get_type(ei_x_buff* buf, int *type, int *size);

int ei_x_decode_version(ei_x_buff* buf, int *version);
int ei_x_decode_long(ei_x_buff* buf, long *p);
int ei_x_decode_ulong(ei_x_buff* buf, unsigned long *p);
int ei_x_decode_double(ei_x_buff* buf, double *p);
int ei_x_decode_boolean(ei_x_buff* buf, int *p);
int ei_x_decode_char(ei_x_buff* buf, char *p);
int ei_x_decode_string(ei_x_buff* buf, char *p);
int ei_x_decode_atom(ei_x_buff* buf, char *p);
int ei_x_decode_binary(ei_x_buff* buf, void *p, long *len);
int ei_x_decode_fun(ei_x_buff* buf, erlang_fun* p);
int ei_x_decode_pid(ei_x_buff* buf, erlang_pid *p);
int ei_x_decode_port(ei_x_buff* buf, erlang_port *p);
int ei_x_decode_ref(ei_x_buff* buf, erlang_ref *p);
int ei_x_decode_term(ei_x_buff* buf, void *t);
int ei_x_decode_trace(ei_x_buff* buf, erlang_trace *p);
int ei_x_decode_tuple_header(ei_x_buff* buf, int *arity);
int ei_x_decode_list_header(ei_x_buff* buf, int *arity);
int ei_x_decode_ei_term(ei_x_buff* buf, ei_term* term);
int ei_x_print_term(FILE *fp, ei_x_buff* buf);
int ei_x_s_print_term(char** s, ei_x_buff* buf);

/* -------------------------------------------------------------------- */
/*            Encoding/decoding bugnums to GNU MP format                */
/* -------------------------------------------------------------------- */

/* If the user included <gmp.h> we supply some more functions */

#if defined(__GNU_MP_VERSION) \
	&& __GNU_MP_VERSION == 4 && __GNU_MP_VERSION_MINOR >= 1 

int ei_x_decode_bignum(ei_x_buff* buf, mpz_t obj);

#endif /* __GNU_MP_VERSION */

/* -------------------------------------------------------------------- */
/*            Function definitions not documented FIXME                 */
/* -------------------------------------------------------------------- */

#ifndef VXWORKS
int ei_x_decode_longlong(ei_x_buff* buf, EI_LONGLONG *p);
int ei_x_decode_ulonglong(ei_x_buff* buf, EI_ULONGLONG *p);
#endif

#ifdef USE_EI_UNDOCUMENTED

/* 
 * Decode a list of integers into an integer array (i.e. even if it is
 * encoded as a string). count gets number of items in array.
 * See "decode_intlist.c".
 */

int ei_x_decode_intlist(ei_x_buff* buf, long *a, int *count);

int ei_x_decode_big(ei_x_buff* buf, erlang_big* p);

#endif /* USE_EI_UNDOCUMENTED */

#ifdef __cplusplus
}
#endif

#endif // __EIEI_
