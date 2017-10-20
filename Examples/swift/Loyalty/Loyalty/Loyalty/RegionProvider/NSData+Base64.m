//
//  NSData+Base64.m
//
// Derived from http://colloquy.info/project/browser/trunk/NSDataAdditions.h?rev=1576
// Created by khammond on Mon Oct 29 2001.
// Formatted by Timothy Hatcher on Sun Jul 4 2004.
// Copyright (c) 2001 Kyle Hammond. All rights reserved.
// Original development by Dave Winer.
//

#import "NSData+Base64.h"

#import <Foundation/Foundation.h>

static char encodingTable[64] = {
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
		'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
		'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
		'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/' };

@implementation NSData (Base64)

- (NSString *) base64EncodingWithLineLength:(unsigned int) lineLength {
	const unsigned char	*bytes = [self bytes];
	NSMutableString *result = [NSMutableString stringWithCapacity:[self length]];
	unsigned long ixtext = 0;
	unsigned long lentext = [self length];
	long ctremaining = 0;
	unsigned char inbuf[3], outbuf[4];
	short i = 0;
	unsigned int charsonline = 0;
    short ctcopy = 0;
	unsigned long ix = 0;

	while( YES ) {
		ctremaining = lentext - ixtext;
		if( ctremaining <= 0 ) break;

		for( i = 0; i < 3; i++ ) {
			ix = ixtext + i;
			if( ix < lentext ) inbuf[i] = bytes[ix];
			else inbuf [i] = 0;
		}

		outbuf [0] = (inbuf [0] & 0xFC) >> 2;
		outbuf [1] = ((inbuf [0] & 0x03) << 4) | ((inbuf [1] & 0xF0) >> 4);
		outbuf [2] = ((inbuf [1] & 0x0F) << 2) | ((inbuf [2] & 0xC0) >> 6);
		outbuf [3] = inbuf [2] & 0x3F;
		ctcopy = 4;

		switch( ctremaining ) {
		case 1: 
			ctcopy = 2; 
			break;
		case 2: 
			ctcopy = 3; 
			break;
		}

		for( i = 0; i < ctcopy; i++ )
			[result appendFormat:@"%c", encodingTable[outbuf[i]]];

		for( i = ctcopy; i < 4; i++ )
			[result appendFormat:@"%c",'='];

		ixtext += 3;
		charsonline += 4;

		if( lineLength > 0 ) {
			if (charsonline >= lineLength) {
				charsonline = 0;
				[result appendString:@"\n"];
			}
		}
	}

	return result;
}

@end
