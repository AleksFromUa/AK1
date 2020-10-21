#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <map>
#include <string>


using namespace std;

int main(int argc, char *argv[]){
    int rez=0;
	map <string, bool> used;

	int option_index = -1;
	const char* short_options = "hlvLiV::.";
	
	const struct option long_options[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
		{"lorem",0,NULL,'L'},
		{"ipsum",0,NULL,'i'},
		{"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };

	while ((rez = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){
		switch (rez){
		case 'h': {
			if (used["h"] == false) {
				printf("\n ------HELP------\n-l --list\n-h --help\n-v --version\n-L --lorem\n-i --ipsum\n-V<N> --value=<N>\n\n"); 
				used["h"] = true;
				break;
			} 
			break;
		}

		case 'l': {
			if (used["l"] == false) {
				printf("Out: [list]\n"); 
				used["l"] = true;
				break;
			}
			break;
		}

		case 'v': {
			if (used["v"] == false) {
				printf("Out: Version\n"); 
				used["v"] = true;
				break;
			}
			break;
		}

        case 'L': {
			if (used["L"] == false) {
				printf("Out: Lorem ipsum dolor sit amen\n"); 
				used["L"] = true;
				break;
			}
			break;
		}

        case 'i': {
			if (used["i"] == false) {
				printf("Out: ipsum Lorem dolor amen sit\n"); 
				used["i"] = true;
				break;
			}
			break;
		}

		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("Out: value\n"); 
					used["V"] = true;
				} else {
					printf("Out: %s value\n", optarg); 
					used["V"] = true;
				}
				
				break;
			}
			break;
		}

		case '.': default: {
			printf("%c invalid parameter\n", rez);
			break;
			}
        };
		option_index = -1;
	};
};