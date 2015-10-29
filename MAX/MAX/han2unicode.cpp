#include "han2unicode.h"



han2unicode::han2unicode()
{
	ksc5601max  = sizeof(tabksc5601) / sizeof(tabksc5601[0]) - 1;
}


han2unicode::~han2unicode()
{
}

void han2unicode::hangle2unicode(char * src, Uint16 * dest)
{
	while (*src) {
		if (*src > 0 && *src < 128) {
			*dest++ = *src++;
		}
		else {
			*dest++ = convert_char_ksc5601_to_ucs2(src[0], src[1]);
			src += 2;
		}
	}
	*dest = 0;
}

unsigned short han2unicode::convert_char_ksc5601_to_ucs2(unsigned char byte1, unsigned char byte2)
{
	int tab_idx = ((int)byte1 - 0x00a1) * 94 + (int)byte2 - 0x00a1;
	long code_ucs2;

	if (tab_idx >= 0 && tab_idx < ksc5601max) {
		code_ucs2 = tabksc5601[tab_idx];
		if (code_ucs2 != -1) return code_ucs2;
	}
	return 0;
}
