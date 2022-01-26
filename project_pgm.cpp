#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <time.h> 
int pat[100],pat1[100],arr[1000],arr1[1000],arr2[1000];
int r,num,kx;int pos[100];int fin_pos[100],pos1[100];
void heapify(int fin_arrx[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
  
    if (l < n && fin_arrx[l] > fin_arrx[largest]) 
        largest = l; 
  
     
    if (r < n && fin_arrx[r] > fin_arrx[largest]) 
        largest = r; 
  
    
    if (largest != i) 
    { 
        int temp=fin_arrx[i];
        fin_arrx[i]=fin_arrx[largest];
        fin_arrx[largest]=temp;
        heapify(fin_arrx, n, largest); 
    } 
} 
void heapSort(int fin_arrx[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(fin_arrx, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        int temp=fin_arrx[0];
        fin_arrx[0]=fin_arrx[i];
        fin_arrx[i]=temp;
        heapify(fin_arrx, i, 0); 
    } 
} 
int * getarr( int x) {

   static int  r[10],r1[10];
   int c=0;

   while(x!=0)
      {
        r[c]=x%10;
        x/=10;
        c++;
      }
    int i=0;
    c=c-1;
    while(c>=0)
     {
         r1[i]=r[c];
         i++;
         c--;
     }

   return r1;
}
int findlen(int x)
 {
     int r,c=0;

   while(x!=0)
      {
        r=x%10;
        x/=10;
        c++;
      } 
    return c;
 }
int  *split_it1(int arr[],int n1)
{   int *px;
    int k=0;
    for(int i=0;i<n1;i++)
     {
         int c1=findlen(arr[i]);
         if(c1>1)
          {
            px=getarr(arr[i]);
            for(int j=0;j<c1;j++)
             {
                 arr2[j+k]=*(px+j);
             }
            k+=c1;
          }
         else
          {   arr2[k]=arr[i];
              k++;
          }
     }
    return arr2;
}
  int  *split_it(int arr[],int n1)
{   int *px;
    int k=0;
    for(int i=0;i<n1;i++)
     {
         int c1=findlen(arr[i]);
         if(c1>1)
          {
            px=getarr(arr[i]);
            for(int j=0;j<c1;j++)
             {
                 arr1[j+k]=*(px+j);
             }
            k+=c1;
          }
         else
          {   arr1[k]=arr[i];
              k++;
          }
     }
    return arr1;
}
void computeLPSArray(int* pat, int M, int* lps) 
{ 
    
    int len = 0; 
  
    lps[0] = 0; 
  
   
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
             
            if (len != 0) { 
                len = lps[len - 1]; 
  
                
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
int Search1(int* pat, int* txt,int r1,int r2) 
{ 
    int M = r1;
    int N = r2; 
    printf("patter len:%d",r1);
    printf("\n");
    int lps[M]; 
    kx=0;
    computeLPSArray(pat, M, lps); 
  
    int i = 0; 
    int j = 0;  
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            pos1[kx]=i-j;
            printf("%d",pos1[kx]);
            kx++;
            j = lps[j - 1]; 
        } 
  
        
        else if (i < N && pat[j] != txt[i]) { 
            
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
	return kx; 
}
int Search(int* pat, int* txt,int r1,int r2) 
{ 
    int M = r1;
    int N = r2; 
    printf("patter len:%d",r1);
    printf("\n");
    int lps[M]; 
    kx=0;
    computeLPSArray(pat, M, lps); 
  
    int i = 0; 
    int j = 0;  
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            pos[kx]=i-j;
            printf("%d",pos[kx]);
            kx++;
            j = lps[j - 1]; 
        } 
  
        
        else if (i < N && pat[j] != txt[i]) { 
            
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
	return kx; 
} 
void delay(int number_of_seconds) 
{ 
    
    int milli_seconds = 100 * number_of_seconds; 
  
    clock_t start_time = clock(); 
  
    while (clock() < start_time + milli_seconds) 
        ; 
} 
int mergeit(int xrr[],int n)
 {
    int s=0;
    for(int i=0;i<n;i++)
     {
         s+=xrr[i]*(pow(10,n-i-1));
     }
    return s;
 }

int compare(int a,int b) {


   int *p,*p1;
   int len1,len2;
   int fin[100],fin1[100];
   int sum=0,sum1=0;
   len1=findlen(a);
   len2=findlen(b);
  
   p = getarr(a);
   for(int i=0;i<len1;i++)
    {
     fin[i]=*(p+i);
     fin1[len2+i]=*(p+i);
     
    }
   p1= getarr(b);
   for(int i=0;i<len2;i++)
    {
     fin[len1+i]=*(p1+i);
     fin1[i]=*(p1+i);
     
    }
   
   int t=len1+len2;
   sum=mergeit(fin,t);
   sum1=mergeit(fin1,t);
   if(sum>sum1)
    {
        return 1;
    }
   else if(sum<sum1)
    {
        return -1;
    }
   else if(sum==sum1)
    {
        return 0;
    }
    
}  

 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int arr[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (compare(pivot,arr[j])==-1)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
 
void quick_sort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partion(arr, p, q);
        quick_sort(arr, p, j-1);
        quick_sort(arr, j+1, q);
    }
}
void randgen(int arr[],int n1)
  {
  	int lower=0;
  	int upper;
  	int leng=n1;
  	if(leng%2==9)
    upper=leng/2;
    else
    upper=(leng+1)/2;
    upper-=5;
    num = (rand() % (upper - lower + 1)) + lower;
    int num2=(rand() % ((leng-num-1) - 0 + 1)) + 4;
    r=num2+num;
    int j=0;
    for(int i=num2;i<=r;i++)
     {
       pat[j]=arr[i];
       j++;
      }
    
} 
int main()
{
	 for (int i = 0; i < 20; i++) { 
        delay(1); 
        printf("="); 
    } 
    delay(1);
    printf("\n");
    printf("CODE GENERATOR");
    printf("\n");
     for (int i = 0; i < 20; i++) { 
        delay(1); 
        printf("="); 
    } 
	int arr[] = { 87, 12, 46, 32,57, 196};
	printf("\n enter the pattern length");
	int patlen;
	scanf("%d",&patlen);
	printf("\n enter your pattern");
	for(int i=0;i<patlen;i++)
	 {
	 	scanf("%d",&pat1[i]);
	 }
	int *fin_arr,*fin_arrx;
	int n = sizeof(arr)/sizeof(arr[0]);
	int nf=0;
    quick_sort(arr, 0, n-1);
    fin_arr=split_it(arr,n);
    int i=0;
    while(*(fin_arr+i)!=NULL)
     {
         nf++;
         i++;
     }
    nf++;
    randgen(fin_arr,nf);
    printf("\n");
   // randgen(arrx,nx);
    int txt[]={9,1,2,9,9};
    int kx1=Search(pat,fin_arr,num,nf);
    printf("\n");
    int ix=0;
    int countx=0;
    printf("%d",pos[0]);
    for(ix;ix<kx1;ix++)
     {
     	fin_pos[ix]=pos[ix];
     	countx++;
	 }
	int jx=ix;
    int kx2=Search1(pat1,fin_arr,patlen,nf);
    printf("\n");
    int cx=0;
   // fin_pos[2]=pos1[0];
  //  countx++;
    for(int ih=kx1;ih<kx2+kx1;ih++)
     {
		fin_pos[ih]=pos1[cx];
     	cx++;
     	countx++;
	 }
    printf("\n");
    printf("%d",fin_pos[2]);
    for(int g=0;g<countx;g++)
     {
     	printf("%d",fin_pos[g]);
	 }
	fin_arrx=split_it1(fin_pos,countx);
	int jz=0;
	int nx1=0;
	while(*(fin_arrx+jz)!=NULL)
     {
         nx1++;
         jz++;
     }
   // printf("fin len:%d",nx1);
    printf("\n");
    heapSort(fin_arrx,nx1);
    int numx=mergeit(fin_arrx,nx1);
    printf("%d",numx);
    printf("\n");
    for (int i = 0; i < nf; i++)
         printf("%d", fin_arr[i]);
    return 0;
}


