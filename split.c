/******************************************************************************

                            Code to divide
							the entered input code into
							20 bytes packets

*******************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    char input_string[100];// ="helloworldthisismetalkingtoyouthroughspace";
    char output_string[100][100];
    int i,j, length;
    static int k=0;
    printf("Enter the code: ");
    scanf("%s",input_string);
    length=strlen(input_string);
    for(i=0; i<=length/20;i++)
    {
        for(j=0;j<20; j++)
        {
        output_string[i][j]=input_string[k];
        k++;
        }
    }

    for(i=0; i<=length/20;i++){
        for(j=0;j<20; j++){
        printf("%c",output_string[i][j]);
        }
        printf("\n");
    }
        
    return 0;
}