/*
 * @Author: xinyuan 
 * @Date: 2020-02-17 23:55:24 
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-18 00:12:50
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char * addBinary(char * a, char * b);
int main()
{
    char *x = addBinary("1111", "1111");
    return 0;
}

char * addBinary(char * a, char * b){
    char *bin, *temp;       /* bin为相加后的字符串，temp为长的那个字符串 */
    int n, alen = strlen(a), blen = strlen(b);          /* n 为bin的长度，minlen为短字符串的长度 */
    int flag = 0;   //标记是否进位
    if(alen > blen)
    {
        n = alen + 1;
        temp = a;
    }
    else
    {
        n = blen + 1;
        temp = b;
    }
    bin = (char *)malloc((n + 1) * sizeof(char));
    bin[n] = '\0';
    while(alen && blen)
    {
        bin[--n] = a[--alen] + b[--blen] - '0' + flag;
        if(bin[n] == '2')
        {
            flag = 1;
            bin[n] = '0';
        }
        else if(bin[n] == '3')
        {
            flag = 1;
            bin[n] = '1';
        }
        else
        {
            flag = 0;
        }
    }
    while(--n >= 1)
    {
        bin[n] = temp[n - 1] + flag;
        if(bin[n] == '2')
        {
            flag = 1;
            bin[n] = '0';
        }
        else
        {
            flag = 0;
        }
    }
    if(flag)
    {
        bin[0] = '1';
        return bin;
    }
    return bin + 1;

}
