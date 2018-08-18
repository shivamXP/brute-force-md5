
/*  group members : Shivam Patel
			 : Murali Siddappa Badiger 
		      : Rasheed Azeez			 
*/

#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
void hash(char in[]);
unsigned char converted[32];
unsigned char target[32]="acc078c68821d92947bbc24ed5c62024";

void main(int argc, char *argv[])
{
char make[5];
make[4]='\0';
for(int i=0;i<=255;i++){  
   for(int k=0;k<=255;k++){
      for(int s=0;s<=255;s++){ 
         for(int p=0;p<=255;p++){
              make[0]=(unsigned char)i;
              make[1]=(unsigned char)k;
              make[2]=(unsigned char)s;
              make[3]=(unsigned char)p;
              hash(make);


for(int e=0;e<=31;e++){
 if(converted[e]==target[e]){
   if(e==31){
           
         printf("hash matched => %c%c%c%c ",make[0],make[1],make[2],make[3]);
           return;
            }
  continue;
}else{
break;
}

}

}
}
}
}

}

void hash(char in[]){

    EVP_MD_CTX mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    int md_len, i;

    OpenSSL_add_all_digests();

    md = EVP_get_digestbyname("md5");

    EVP_MD_CTX_init(&mdctx);
    EVP_DigestInit_ex(&mdctx, md, NULL);
    EVP_DigestUpdate(&mdctx, in,4);
    EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
    EVP_MD_CTX_cleanup(&mdctx);
    
   printf("checking hash => ");
    for(i = 0; i < md_len; i++) printf("%02x", md_value[i]);
    printf("\n");

    for(i=0;i<md_len;i++){
    sprintf(&converted[i*2],"%02x",md_value[i]);
    }
    converted[32]='\0';
     

}

