// :mode=c++:
/*
decode.h - c++ wrapper for a base64 decoding algorithm

This is part of the libb64 project, and has been placed in the public domain.
For details, see http://sourceforge.net/projects/libb64
*/

#ifndef BASE64_DECODE_H
#define BASE64_DECODE_H

#include <iostream>

namespace s11n
{
namespace base64
{
	
	extern "C"
	{
		#include "base64dec.h"
	}
	
	struct decoder
	{
		base64_decodestate _state;
		int _buffersize;
		
		decoder(int buffersize_in = 4096)
		: _buffersize(buffersize_in)
		{}
		int decode(char value_in)
		{
			return base64_decode_value(value_in);
		}
		int decode(const char* code_in, const int length_in, char* plaintext_out)
		{
			return base64_decode_block(code_in, length_in, plaintext_out, &_state);
		}
		void decode(std::istream& istream_in, std::ostream& ostream_in)
		{
			base64_init_decodestate(&_state);
			//
			const int N = _buffersize;
			char* code = new char[N];
			char* plaintext = new char[N];
			int codelength;
			int plainlength;
			
			do
			{
				istream_in.read((char*)code, N);
				codelength = istream_in.gcount();
				plainlength = decode(code, codelength, plaintext);
				ostream_in.write((const char*)plaintext, plainlength);
			}
			while (istream_in.good() && codelength > 0);
			//
			base64_init_decodestate(&_state);
			
			delete [] code;
			delete [] plaintext;
		}
	};
	
} // namespace base64
} // namespace s11n
#endif // BASE64_DECODE_H
