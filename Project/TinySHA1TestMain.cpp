/* 
 *
 * TinySHA1 - a header only implementation of the SHA1 algorithm. Based
 * on the implementation in boost::uuid::details
 * 
 * Copyright (c) 2012-22 SAURAV MOHAPATRA <mohaps@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
 
#include "TinySHA1.h"
#include "TinySHA1Optim.h"
#include <iostream>
#include <string>
#include <fstream>

int compare(char a[],char b[]){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

void testSHA1(const std::string& val) {
	plt::SHA1 s;
	s.processBytes(val.c_str(), val.size());
	uint32_t digest[5];
	s.getDigest(digest);	
	char tmp[48];
	snprintf(tmp, 45, "%08x %08x %08x %08x %08x", digest[0], digest[1], digest[2], digest[3], digest[4]);
	std::cout<<"Hashed Result of SHA1: "<<tmp<<std::endl;

	pltoptim::SHA1 ss;
	ss.processBytes(val.c_str(), val.size());
	uint32_t digestOpt[5];
	ss.getDigest(digestOpt);
	char tmpOpt[48];
	snprintf(tmpOpt, 45, "%08x %08x %08x %08x %08x", digestOpt[0], digestOpt[1], digestOpt[2], digestOpt[3], digestOpt[4]);
	std::cout<<"Hashed result of SHA1 Optimized: "<<tmpOpt<<std::endl;
	int result = compare(tmp, tmpOpt);
	result == 0 ? std::cout << "Failure!" << std::endl : std::cout << "Success!" << std::endl;
}

int main(int argc, char **argv) {
	std::ifstream ifs("WarAndPeace.txt");
	if (ifs.is_open())
	{
		std::string line;
		while(true) {
			while (std::getline(ifs, line)) {
				//char* lineToHash = new char [line.length()+1];
				//strcpy(lineToHash, line.c_str());
				testSHA1(line);
			}	
			if(ifs.eof()) break;
			ifs.clear();
		}
	}
	return 0;
}
