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

#include "eiei.h"

int ei_x_get_type(ei_x_buff* buf, int *type, int *size)
{
  return ei_get_type(buf->buff, &buf->index, type, size);
}

int ei_x_decode_version(ei_x_buff* buf, int *version)
{
  return ei_decode_version(buf->buff, &buf->index, version);
}

int ei_x_decode_long(ei_x_buff* buf, long *p)
{
  return ei_decode_long(buf->buff, &buf->index, p);
}

int ei_x_decode_ulong(ei_x_buff* buf, unsigned long *p)
{
  return ei_decode_ulong(buf->buff, &buf->index, p);
}

int ei_x_decode_double(ei_x_buff* buf, double *p)
{
  return ei_decode_double(buf->buff, &buf->index, p);
}

int ei_x_decode_boolean(ei_x_buff* buf, int *p)
{
  return ei_decode_boolean(buf->buff, &buf->index, p);
}

int ei_x_decode_char(ei_x_buff* buf, char *p)
{
  return ei_decode_char(buf->buff, &buf->index, p);
}

int ei_x_decode_string(ei_x_buff* buf, char *p)
{
  return ei_decode_string(buf->buff, &buf->index, p);
}

int ei_x_decode_atom(ei_x_buff* buf, char *p)
{
  return ei_decode_atom(buf->buff, &buf->index, p);
}

int ei_x_decode_binary(ei_x_buff* buf, void *p, long *len)
{
  return ei_decode_binary(buf->buff, &buf->index, p, len);
}

int ei_x_decode_fun(ei_x_buff* buf, erlang_fun* p)
{
  return ei_decode_fun(buf->buff, &buf->index, p);
}

int ei_x_decode_pid(ei_x_buff* buf, erlang_pid *p)
{
  return ei_decode_pid(buf->buff, &buf->index, p);
}

int ei_x_decode_port(ei_x_buff* buf, erlang_port *p)
{
  return ei_decode_port(buf->buff, &buf->index, p);
}

int ei_x_decode_ref(ei_x_buff* buf, erlang_ref *p)
{
  return ei_decode_ref(buf->buff, &buf->index, p);
}

int ei_x_decode_term(ei_x_buff* buf, void *t)
{
  return ei_decode_term(buf->buff, &buf->index, t);
}

int ei_x_decode_trace(ei_x_buff* buf, erlang_trace *p)
{
  return ei_decode_trace(buf->buff, &buf->index, p);
}

int ei_x_decode_tuple_header(ei_x_buff* buf, int *arity)
{
  return ei_decode_tuple_header(buf->buff, &buf->index, arity);
}

int ei_x_decode_list_header(ei_x_buff* buf, int *arity)
{
  return ei_decode_list_header(buf->buff, &buf->index, arity);
}
int ei_x_decode_ei_term(ei_x_buff* buf, ei_term* term)
{
  return ei_decode_ei_term(buf->buff, &buf->index, term);
}


int ei_x_print_term(FILE *fp, ei_x_buff* buf)
{
  return ei_print_term(fp, buf->buff, &buf->index);
}

int ei_x_s_print_term(char** s, ei_x_buff* buf)
{
  return ei_s_print_term(s, buf->buff, &buf->index);
}

#if defined(__GNU_MP_VERSION) \
	&& __GNU_MP_VERSION == 4 && __GNU_MP_VERSION_MINOR >= 1 

int ei_x_decode_bignum(ei_x_buff* buf, mpz_t obj)
{
  return ei_decode_bignum(buf->buff, &buf->index, obj);
}

#endif /* __GNU_MP_VERSION */

#ifndef VXWORKS
int ei_x_decode_longlong(ei_x_buff* buf, EI_LONGLONG *p)
{
  return ei_decode_longlong(buf->buff, &buf->index, p);
}

int ei_x_decode_ulonglong(ei_x_buff* buf, EI_ULONGLONG *p)
{
  return ei_decode_ulonglong(buf->buff, &buf->index, p);
}

#endif

#ifdef USE_EI_UNDOCUMENTED

int ei_x_decode_intlist(ei_x_buff* buf, long *a, int *count)
{
  return ei_decode_intlist(buf->buff, &buf->index, a, count);
}

int ei_x_decode_big(ei_x_buff* buf, erlang_big* p)
{
  return ei_decode_big(buf->buff, &buf->index, p);
}

#endif /* USE_EI_UNDOCUMENTED */
