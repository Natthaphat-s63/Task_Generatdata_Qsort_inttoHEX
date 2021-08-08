


/*# convert an integer to a hex string
def to_hex( value ):
    HEX_DIGITS = '0123456789abcdef'
    s = ''
    if (value < 0):
        value += (1 << 32)  # 32-bit value
    while True:
        d = HEX_DIGITS[ value & 0xf ]
        s = d + s
        value >>= 4
        if value == 0:
            break
    s = '0x' + s
    return s

if __name__ == "__main__": # some test code
    print (to_hex(33))  # 0x21
    print (to_hex(-1))  # 0xffffffff*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char* to_hex(int64_t val)
{
    char* HEX_DIGITS = "0123456789abcdef";
    char* s = malloc(sizeof(char)*10);
    if(val<0)
    {
        int64_t a =1;
        val+=(a<<32);
    }
    int limit =0;
    while (1)
    {
        char d[2] = {HEX_DIGITS[val & 0xf],'\0'};
        
        char* tmp= strdup(s);
        strcpy(s,d);
        strcat(s,tmp);
        free(tmp);

        val >>=4;
        limit++;
        if (val==0 || limit==8)break;
    }
    char* f = "0x";
    char* tmp2= strdup(s);
    strcpy(s,f);
    strcat(s,tmp2);
    free(tmp2);
    return(s);
}


int main(){
    char* ans = to_hex(33);
    int i =0;

    while (ans[i] != '\0')
    {
        printf("%c",ans[i]);
        i++;
    }
    free(ans);
    return 0;
}
