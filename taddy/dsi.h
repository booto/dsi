#ifndef _DSI_H_
#define _DSI_H_

#include "aes.h"

typedef struct
{
	unsigned char ctr[16];
	unsigned char mac[16];
	unsigned char S0[16];
	unsigned int maclen;

    aes_context aes;
}
dsi_context;

#ifdef __cplusplus
extern "C" {
#endif

void		dsi_set_key( dsi_context* ctx, 
						 unsigned char key[16] );

void		dsi_add_ctr( dsi_context* ctx,
						 unsigned char carry );

void		dsi_set_ctr( dsi_context* ctx, 
						 unsigned char ctr[16] );

void		dsi_init_ctr( dsi_context* ctx, 
						  unsigned char key[16], 
						  unsigned char ctr[12] );

void		dsi_crypt_ctr_block( dsi_context* ctx, 
								 unsigned char input[16], 
								 unsigned char output[16] );

void		dsi_init_ccm( dsi_context* ctx,
						  unsigned char key[16],
						  unsigned int maclength,
						  unsigned int payloadlength,
						  unsigned int assoclength,
						  unsigned char nonce[12] );

void		dsi_encrypt_ccm_block( dsi_context* ctx, 
								   unsigned char input[16], 
								   unsigned char output[16],
								   unsigned char* mac );

void		dsi_decrypt_ccm_block( dsi_context* ctx, 
								   unsigned char input[16], 
								   unsigned char output[16],
								   unsigned char* mac );


void		dsi_decrypt_ccm( dsi_context* ctx, 
							 unsigned char* input, 
							 unsigned char* output,
							 unsigned int size,
							 unsigned char* mac );

int			dsi_es_decrypt( unsigned char* buffer,
						    unsigned char key[16],
						    unsigned char metablock[32],
							unsigned int size );

#ifdef __cplusplus
}
#endif

#endif // _DSI_H_
