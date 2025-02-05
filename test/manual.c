/** @std C11 */
#include <inttypes.h>

/*->*/
static const uint32_t utf32_word_edges[] = {
	/* 6 code-points. */
	0x30, 0x3a, 0x41, 0x5b, 0x61, 0x7b,
	/* 56 code-points. */
	0xc2aa, 0xc2ab, 0xc2b5, 0xc2b6, 0xc2ba, 0xc2bb, 0xc380, 0xc397, 0xc398,
	0xc3b7, 0xc3b8, 0xcab0, 0xcdb0, 0xcdb4, 0xcdb6, 0xcdba, 0xcdbb, 0xcdbe,
	0xcdbf, 0xce84, 0xce86, 0xce87, 0xce88, 0xcfb6, 0xcfb7, 0xd282, 0xd28a,
	0xd599, 0xd5a0, 0xd689, 0xd790, 0xd7b3, 0xd8a0, 0xd980, 0xd981, 0xd98b,
	0xd9a0, 0xd9aa, 0xd9ae, 0xd9b0, 0xd9b1, 0xdb94, 0xdb95, 0xdb96, 0xdbae,
	0xdbbd, 0xdbbf, 0xdc80, 0xdc90, 0xdc91, 0xdc92, 0xdcb0, 0xdd8d, 0xdea6,
	0xdeb1, 0xdfab,
	/* 406 code-points. */
	0xe0a080, 0xe0a096, 0xe0a180, 0xe0a199, 0xe0a1a0, 0xe0a288, 0xe0a289,
	0xe0a290, 0xe0a2a0, 0xe0a389, 0xe0a484, 0xe0a4ba, 0xe0a4bd, 0xe0a4be,
	0xe0a590, 0xe0a591, 0xe0a598, 0xe0a5a2, 0xe0a5a6, 0xe0a5b0, 0xe0a5b2,
	0xe0a681, 0xe0a685, 0xe0a6bc, 0xe0a6bd, 0xe0a6be, 0xe0a78e, 0xe0a797,
	0xe0a79c, 0xe0a7a2, 0xe0a7a6, 0xe0a7b2, 0xe0a7bc, 0xe0a7bd, 0xe0a885,
	0xe0a8bc, 0xe0a999, 0xe0a9b0, 0xe0a9b2, 0xe0a9b5, 0xe0aa85, 0xe0aabc,
	0xe0aabd, 0xe0aabe, 0xe0ab90, 0xe0aba2, 0xe0aba6, 0xe0abb0, 0xe0abb9,
	0xe0abba, 0xe0ac85, 0xe0acbc, 0xe0acbd, 0xe0acbe, 0xe0ad9c, 0xe0ada2,
	0xe0ada6, 0xe0adb0, 0xe0adb1, 0xe0adb2, 0xe0ae83, 0xe0aebe, 0xe0af90,
	0xe0af97, 0xe0afa6, 0xe0afb0, 0xe0b085, 0xe0b0bc, 0xe0b0bd, 0xe0b0be,
	0xe0b198, 0xe0b1a2, 0xe0b1a6, 0xe0b1b7, 0xe0b280, 0xe0b281, 0xe0b285,
	0xe0b2bc, 0xe0b2bd, 0xe0b2be, 0xe0b39d, 0xe0b3a2, 0xe0b3a6, 0xe0b3b3,
	0xe0b484, 0xe0b4bb, 0xe0b4bd, 0xe0b4be, 0xe0b58e, 0xe0b58f, 0xe0b594,
	0xe0b597, 0xe0b59f, 0xe0b5a2, 0xe0b5a6, 0xe0b5b0, 0xe0b5ba, 0xe0b681,
	0xe0b685, 0xe0b78a, 0xe0b7a6, 0xe0b7b2, 0xe0b881, 0xe0b8b1, 0xe0b8b2,
	0xe0b8b4, 0xe0b980, 0xe0b986, 0xe0b990, 0xe0b99a, 0xe0ba81, 0xe0bab1,
	0xe0bab2, 0xe0bab4, 0xe0babd, 0xe0bb86, 0xe0bb90, 0xe0bc81, 0xe0bca0,
	0xe0bcaa, 0xe0bd80, 0xe0bdb1, 0xe0be88, 0xe0be8d, 0xe18080, 0xe180ab,
	0xe180bf, 0xe1818a, 0xe18190, 0xe18196, 0xe1819a, 0xe1819e, 0xe181a1,
	0xe181a2, 0xe181a5, 0xe181a7, 0xe181ae, 0xe181b1, 0xe181b5, 0xe18282,
	0xe1828e, 0xe1828f, 0xe18290, 0xe1829a, 0xe182a0, 0xe183bb, 0xe183bd,
	0xe18d9d, 0xe18e80, 0xe18e90, 0xe18ea0, 0xe19080, 0xe19081, 0xe199ad,
	0xe199af, 0xe19a80, 0xe19a81, 0xe19a9b, 0xe19aa0, 0xe19bab, 0xe19bb1,
	0xe19c92, 0xe19c9f, 0xe19cb2, 0xe19d80, 0xe19d92, 0xe19da0, 0xe19db2,
	0xe19e80, 0xe19eb4, 0xe19f9c, 0xe19f9d, 0xe19fa0, 0xe19fb0, 0xe1a090,
	0xe1a183, 0xe1a184, 0xe1a285, 0xe1a287, 0xe1a2a9, 0xe1a2aa, 0xe1a4a0,
	0xe1a586, 0xe1a79a, 0xe1a880, 0xe1a897, 0xe1a8a0, 0xe1a995, 0xe1aa80,
	0xe1aaa0, 0xe1ac85, 0xe1acb4, 0xe1ad85, 0xe1ad8e, 0xe1ad90, 0xe1ad9a,
	0xe1ae83, 0xe1aea1, 0xe1aeae, 0xe1afa6, 0xe1b080, 0xe1b0a4, 0xe1b180,
	0xe1b1b8, 0xe1b280, 0xe1b380, 0xe1b3a9, 0xe1b3ad, 0xe1b3ae, 0xe1b3b4,
	0xe1b3b5, 0xe1b3b7, 0xe1b3ba, 0xe1b4ac, 0xe1b5ab, 0xe1b5b8, 0xe1b5b9,
	0xe1b69b, 0xe1b880, 0xe1bebd, 0xe1bebe, 0xe1bebf, 0xe1bf82, 0xe1bf8d,
	0xe1bf90, 0xe1bf9d, 0xe1bfa0, 0xe1bfad, 0xe1bfb2, 0xe1bfbd, 0xe28482,
	0xe28483, 0xe28487, 0xe28488, 0xe2848a, 0xe28494, 0xe28495, 0xe28496,
	0xe28499, 0xe2849e, 0xe284a4, 0xe284a5, 0xe284a6, 0xe284a7, 0xe284a8,
	0xe284a9, 0xe284aa, 0xe284ae, 0xe284af, 0xe284ba, 0xe284bc, 0xe28580,
	0xe28585, 0xe2858a, 0xe2858e, 0xe2858f, 0xe28683, 0xe28685, 0xe2b080,
	0xe2b1bc, 0xe2b1be, 0xe2b3a5, 0xe2b3ab, 0xe2b3af, 0xe2b3b2, 0xe2b3b9,
	0xe2b480, 0xe2b5af, 0xe2b680, 0xe2b7a0, 0xe38086, 0xe38087, 0xe380bc,
	0xe380bd, 0xe38181, 0xe38299, 0xe3829f, 0xe382a0, 0xe382a1, 0xe383bb,
	0xe383bf, 0xe38690, 0xe386a0, 0xe38780, 0xe387b0, 0xe38880, 0xe39080,
	0xe4b780, 0xe4b880, 0xea8095, 0xea8096, 0xea9290, 0xea9390, 0xea93b8,
	0xea9480, 0xea988c, 0xea9890, 0xea99af, 0xea9a80, 0xea9a9c, 0xea9aa0,
	0xea9ba6, 0xea9ca2, 0xea9db0, 0xea9db1, 0xea9e88, 0xea9e8b, 0xea9fb2,
	0xea9fb5, 0xea9fb8, 0xea9fba, 0xeaa082, 0xeaa083, 0xeaa086, 0xeaa087,
	0xeaa08b, 0xeaa08c, 0xeaa0a3, 0xeaa180, 0xeaa1b4, 0xeaa282, 0xeaa2b4,
	0xeaa390, 0xeaa3a0, 0xeaa3b2, 0xeaa3b8, 0xeaa3bb, 0xeaa3bc, 0xeaa3bd,
	0xeaa3bf, 0xeaa480, 0xeaa4a6, 0xeaa4b0, 0xeaa587, 0xeaa5a0, 0xeaa680,
	0xeaa684, 0xeaa6b3, 0xeaa790, 0xeaa79e, 0xeaa7a0, 0xeaa7a5, 0xeaa7a7,
	0xeaa8a9, 0xeaa980, 0xeaa983, 0xeaa984, 0xeaa98c, 0xeaa990, 0xeaa99c,
	0xeaa9a0, 0xeaa9b0, 0xeaa9b1, 0xeaa9b7, 0xeaa9ba, 0xeaa9bb, 0xeaa9be,
	0xeaaab0, 0xeaaab1, 0xeaaab2, 0xeaaab5, 0xeaaab7, 0xeaaab9, 0xeaaabe,
	0xeaab80, 0xeaab81, 0xeaab82, 0xeaab9d, 0xeaaba0, 0xeaabab, 0xeaabb2,
	0xeaabb3, 0xeaac81, 0xeaad9b, 0xeaada0, 0xeaada9, 0xeaadb0, 0xeaafa3,
	0xeaafb0, 0xeda080, 0xefa480, 0xefac9e, 0xefac9f, 0xefaca9, 0xefacaa,
	0xefaeb2, 0xefaf93, 0xefb4be, 0xefb590, 0xefb78f, 0xefb7b0, 0xefb7bc,
	0xefb9b0, 0xefbbbf, 0xefbc90, 0xefbc9a, 0xefbca1, 0xefbcbb, 0xefbd81,
	0xefbd9b, 0xefbda6, 0xefbdb0, 0xefbdb1, 0xefbe9e, 0xefbea0, 0xefbfa0,
	/* 300 code-points. */
	0xf0908080, 0xf0908480, 0xf0908a80, 0xf0908ba0, 0xf0908c80, 0xf0908ca0,
	0xf0908cad, 0xf0908d81, 0xf0908d82, 0xf0908d8a, 0xf0908d90, 0xf0908db6,
	0xf0908e80, 0xf0908e9f, 0xf0908ea0, 0xf0908f90, 0xf0909080, 0xf09095af,
	0xf09095b0, 0xf0909e80, 0xf090a080, 0xf090a197, 0xf090a1a0, 0xf090a1b7,
	0xf090a280, 0xf090a2a7, 0xf090a3a0, 0xf090a3bb, 0xf090a480, 0xf090a496,
	0xf090a4a0, 0xf090a4bf, 0xf090a680, 0xf090a6bc, 0xf090a6be, 0xf090a780,
	0xf090a880, 0xf090a881, 0xf090a890, 0xf090a8b8, 0xf090a9a0, 0xf090a9bd,
	0xf090aa80, 0xf090aa9d, 0xf090ab80, 0xf090ab88, 0xf090ab89, 0xf090aba5,
	0xf090ac80, 0xf090acb9, 0xf090ad80, 0xf090ad98, 0xf090ada0, 0xf090adb8,
	0xf090ae80, 0xf090ae99, 0xf090b080, 0xf090b3ba, 0xf090b480, 0xf090b4a4,
	0xf090b4b0, 0xf090b58e, 0xf090b58f, 0xf090b5a9, 0xf090b5b0, 0xf090b68e,
	0xf090ba80, 0xf090baab, 0xf090bab0, 0xf090bbbc, 0xf090bc80, 0xf090bc9d,
	0xf090bca7, 0xf090bd86, 0xf090bdb0, 0xf090be82, 0xf090beb0, 0xf090bf85,
	0xf090bfa0, 0xf0918080, 0xf0918083, 0xf09180b8, 0xf09181a6, 0xf09181b0,
	0xf09181b1, 0xf09181b3, 0xf09181b5, 0xf09181bf, 0xf0918283, 0xf09182b0,
	0xf0918390, 0xf0918480, 0xf0918483, 0xf09184a7, 0xf09184b6, 0xf0918580,
	0xf0918584, 0xf0918585, 0xf0918587, 0xf09185b3, 0xf09185b6, 0xf0918680,
	0xf0918683, 0xf09186b3, 0xf0918781, 0xf0918785, 0xf0918790, 0xf091879b,
	0xf091879c, 0xf091879d, 0xf0918880, 0xf09188ac, 0xf09188bf, 0xf0918981,
	0xf0918a80, 0xf0918aa9, 0xf0918ab0, 0xf0918b9f, 0xf0918bb0, 0xf0918c80,
	0xf0918c85, 0xf0918cbb, 0xf0918cbd, 0xf0918cbe, 0xf0918d90, 0xf0918d97,
	0xf0918d9d, 0xf0918da2, 0xf0918e80, 0xf0918eb8, 0xf0918f91, 0xf0918f92,
	0xf0918f93, 0xf0918f94, 0xf0919080, 0xf09190b5, 0xf0919187, 0xf091918b,
	0xf0919190, 0xf091919a, 0xf091919f, 0xf09192b0, 0xf0919384, 0xf0919386,
	0xf0919387, 0xf09196af, 0xf0919798, 0xf091979c, 0xf0919880, 0xf09198b0,
	0xf0919984, 0xf09199a0, 0xf0919a80, 0xf0919aab, 0xf0919ab8, 0xf0919ab9,
	0xf0919b80, 0xf0919c9d, 0xf0919cb0, 0xf0919cba, 0xf0919d80, 0xf091a0ac,
	0xf091a2a0, 0xf091a3aa, 0xf091a3bf, 0xf091a4b0, 0xf091a4bf, 0xf091a580,
	0xf091a581, 0xf091a582, 0xf091a590, 0xf091a791, 0xf091a7a1, 0xf091a7a2,
	0xf091a7a3, 0xf091a7a4, 0xf091a880, 0xf091a881, 0xf091a88b, 0xf091a8b3,
	0xf091a8ba, 0xf091a8bb, 0xf091a990, 0xf091a991, 0xf091a99c, 0xf091aa8a,
	0xf091aa9d, 0xf091aa9e, 0xf091aab0, 0xf091ac80, 0xf091af80, 0xf091afa1,
	0xf091afb0, 0xf091b0af, 0xf091b180, 0xf091b181, 0xf091b190, 0xf091b19a,
	0xf091b1b2, 0xf091b292, 0xf091b480, 0xf091b4b1, 0xf091b586, 0xf091b587,
	0xf091b590, 0xf091b68a, 0xf091b698, 0xf091bbb3, 0xf091bc82, 0xf091bc83,
	0xf091bc84, 0xf091bcb4, 0xf091bd90, 0xf091bd9a, 0xf091beb0, 0xf091bf80,
	0xf0928080, 0xf0929080, 0xf0929280, 0xf092bfb1, 0xf0938080, 0xf09390b0,
	0xf0939181, 0xf0939187, 0xf09391a0, 0xf096849e, 0xf09684b0, 0xf096a9ae,
	0xf096a9b0, 0xf096abb0, 0xf096ac80, 0xf096acb0, 0xf096ad90, 0xf096ad9b,
	0xf096ada3, 0xf096b580, 0xf096b583, 0xf096b5ab, 0xf096b5b0, 0xf096ba80,
	0xf096bc80, 0xf096bd8f, 0xf096bd90, 0xf096bd91, 0xf0978080, 0xf09abfb0,
	0xf09b8080, 0xf09bb29c, 0xf09cb3b0, 0xf09cb480, 0xf09d9080, 0xf09d9b81,
	0xf09d9b82, 0xf09d9b9b, 0xf09d9b9c, 0xf09d9bbb, 0xf09d9bbc, 0xf09d9c95,
	0xf09d9c96, 0xf09d9cb5, 0xf09d9cb6, 0xf09d9d8f, 0xf09d9d90, 0xf09d9daf,
	0xf09d9db0, 0xf09d9e89, 0xf09d9e8a, 0xf09d9ea9, 0xf09d9eaa, 0xf09d9f83,
	0xf09d9f84, 0xf09da080, 0xf09dbc80, 0xf09e8080, 0xf09e8480, 0xf09e84b0,
	0xf09e8580, 0xf09e858f, 0xf09e8a90, 0xf09e8aae, 0xf09e8b80, 0xf09e8bac,
	0xf09e8bb0, 0xf09e8bbf, 0xf09e9390, 0xf09e93ab, 0xf09e93b0, 0xf09e97ae,
	0xf09e97b0, 0xf09e97bf, 0xf09e9fa0, 0xf09ea387, 0xf09ea480, 0xf09ea584,
	0xf09ea590, 0xf09ea59e, 0xf09eb880, 0xf09ebbb0, 0xf09fafb0, 0xf3a08081
};
static const uint32_t utf32_word_byte_end[] = { 6, 62, 468, 768 };
/*<-*/

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

static size_t upper_bound(
	const uint32_t *const table,
	size_t low, size_t high,
	const uint32_t key) {
	while(low < high) {
		size_t mid = low + (high - low) / 2;
		if(table[mid] <= key) low = mid + 1;
		else high = mid;
	}
	fprintf(stderr, "(ub(0x%"PRIx32")=0x%"PRIx32")", key, table[low]);
	return low;
}

/** Does not check for the end of the string. Security warning. */
static bool is_word(const char *const string_in_utf8) {
	const uint8_t *const utf8 = (const uint8_t *const)string_in_utf8;
	union { uint32_t u32; uint8_t u8[4]; } internal = { .u32 = 0 };
	size_t ub;
	uint8_t byte = utf8[0];
	if(byte < 0x80) { /* 1 byte? */
		internal.u8[0] = byte;
		ub = upper_bound(utf32_word_edges, 0, utf32_word_byte_end[0],
			internal.u32);
	} else if((byte & 0xe0) == 0xc0) { /* 2 bytes? */
		internal.u8[0] = byte;
		internal.u8[1] = utf8[1];
		ub = upper_bound(utf32_word_edges, utf32_word_byte_end[0], utf32_word_byte_end[1], internal.u32);
	} else {
		assert(0);
	}
	/*fprintf(stderr, "(upper(\"0x%"PRIx32"\") = index %zu:\"0x%"PRIx32"\")\n",
		internal.u32, ub, utf32_word_edges[ub]);*/
	return ub & 1;
}

/*static bool is_word(const char *const codepoint) {
	size_t ub = upper_bound(utf32_word_edges, 0, utf32_word_byte_end[0],
		(uint32_t)(uint8_t)*codepoint);
	fprintf(stderr, "(upper: 0x%zx:\"0x%"PRIx32"\")\n",
		ub, utf32_word_edges[ub]);
	return ub & 1;
}*/

#include "unicode.h"
#include <stdbool.h>

int main(void) {
	int retval = EXIT_FAILURE;
	/*struct test {
		const char *codepoint;
		bool is_word;
	} test[] = {
		{ "`", false },
		{ "a", true },
		{ "z", true },
		{ "{", false },
		{ "_", false },
		{ "\0x7f", false },
		{ "©", false },
		{ "ª", true },
		{ "à", true }
	};
	for(struct test *i = test, *const i_end = test + sizeof test / sizeof *test;
		i < i_end; i++) {
		bool is = is_word(i->codepoint);
		printf("Testing whether \"%s\" is%s a code point in a word: it is%s.\n",
			i->codepoint, i->is_word ? "" : " not", is ? "" : " not");
		assert(i->is_word == is);
	}*/
	struct unicode_deque info = unicode_load();
	if(!info.back) goto catch;

	for(struct unicode_deque_cursor i = unicode_deque_begin(&info);
		unicode_deque_exists(&i); unicode_deque_next(&i)) {
		const struct unicode *const u = unicode_deque_entry(&i);
		bool is_2 = u->category == Ll || u->category == Lu || u->category == Lt
			|| u->category == Lo || u->category == Nd,
			is_utf8 = is_word(u->utf8);
		printf("U+%"PRIx32":0x%"PRIx32": %s (%s).\n",
			u->unicode, u->internal.uint, is_utf8 ? "yes" : "no",
			is_2 ? "yes" : "no");
		assert(is_utf8 == is_2);
	}

	retval = EXIT_SUCCESS;
	goto finally;
catch:
	perror("utf-8 tool");
finally:
	unicode_deque_(&info);
	return retval;
}
