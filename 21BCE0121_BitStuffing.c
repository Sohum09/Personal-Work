#include <stdio.h>
#include <string.h>

int main(){
    int a[50], b[60], i, cnt, j, n, k;
    printf("Enter bit sequence length: ");
    scanf("%d", &n);
    printf("Enter the sequence below [0/1]: \n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    cnt=1; i=0; j=0;
    while(i<n){
        if(a[i]==1){
            b[j] = a[i];
            for(k=i+1; a[k]==1 && cnt<5 && k<n; k++){
                j++;
                b[j] = a[k];
                cnt++;
                if(cnt==5){
                    j++;
                    b[j] = 0;
                }
                i = k;
            }
        }
        else{
            b[j] = a[i];
        }
        i++;
        j++;
        cnt=1;
    }
    printf("\nThe stuffed bits: ");
    for(i=0; i<j; i++)
        printf("%d", b[i]);
    return 0;
}