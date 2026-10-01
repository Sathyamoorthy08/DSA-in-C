#include<stdio.h>
 #include<stdlib.h>

typedef struct dob{int day,month,year}date;
 typedef struct dobs
 {
 int regNo;
 date d;
 }DOB;

typedef struct {int a;char b[4]}pair;

typedef struct {int regNo,credit,gpa;}record;

void swap(DOB *a, DOB *b)
 {
 DOB tem = *a;
 *a = *b;
 *b = tem;
 }

int length(char* s)
 {
 int i=0;
 while(s[i])
 i++;
 return i;
 }

int compare(char* s1,char* s2)
 {
 int n1 = length(s1);int n2 = length(s2);
 int min = (n1<n2)? n1:n2;
 for(int i=0;i<min;i++)
 {
 if(s1[i]<s2[i])
 return 1;
 else if(s1[i]>s2[i])
 return 0;
 }
 return 1;
 }

void copy(char* s1 , char* s2)
 {
 int i=0;
 while(s2[i])
 {
 s1[i] = s2[i];
 i++;
 }
 s1[i]='\0';
 }

void insertionSort(char a[5][30],int n)
 {
 if(n<2) return;
 for(int i=1;i<n;i++)
 {
 char key[30];// = (char*)malloc(sizeof(char)*length(a[i]));
 copy(key,a[i]);
 int j = i-1;
 while(j>=0 && compare(a[j],key) == 0)
 {
 copy(a[j+1],a[j]); j--;
 }copy(a[j+1],key);
 }

}

int compareDOB(DOB d1,DOB d2)
 {
 if(d1.d.year > d2.d.year)
 return 1;
 else if(d1.d.year < d2.d.year)
 return 0;
 else
 {
 if(d1.d.month > d2.d.month)
 return 1;
 else if(d1.d.month < d2.d.month)
 return 0;
 else{
 if(d1.d.day >= d2.d.day) return 1;
 else return 0;
 }
 }
 }

int partition(DOB a[], int l, int h)
 {
 DOB pivot = a[l];
 int i = l;
 for(int j = l+1; j <= h; j++)
 {
 if(compareDOB(pivot,a[j]))
 {
 i=i+1;
 swap(&a[i],&a[j]);
 }
 }
 swap(&a[l],&a[i]);
 return i;
 }

void quickSort(DOB a[], int l, int h)
 {
 if(l<h)
 {
 int k = partition(a,l,h);
 quickSort(a,l,k-1);
 quickSort(a,k+1,h);
 }
 }

void countingSort(pair a1[],int n)
 {
 pair max = a1[0];
 for(int i=1;i<n;i++)
 {
 if(max.a<a1[i].a)
 max = a1[i];
 }
 int *b = (int*)malloc(sizeof(int)*(max.a+1));
 for(int i=0;i<=max.a;i++)
 b[i] = 0;
 for(int i=0;i<n;i++)
 b[a1[i].a]=b[a1[i].a]+1;
 for(int i=1;i<=max.a;i++)
 b[i] += b[i-1];
 pair* c = (pair*)malloc(sizeof(pair)*n);

 for(int i=0;i<n;i++){
 c[i].a = 0; }//c[i].b = 0;}
 for(int i = n-1;i>=0;i--)
 {
 c[b[a1[i].a]-1] = a1[i];
 b[a1[i].a] = b[a1[i].a]-1;
 }
 for(int i=0;i<n;i++)
 a1[i] = c[i];
 }

void merge(record a[], int l, int mid, int h)
 {
 int i = l,j=mid+1,k=0;
 record* b = (record*)malloc(sizeof(record)*(h-l+1));
 while(i <= mid && j <= h)
 {
 if(a[i].credit<a[j].credit)
 {
 b[k] = a[i];k++;i++;
 }
 else {b[k] = a[j];k++;j++;}
 }
 while(i <= mid) b[k++] = a[i++];
 while(j <= h) b[k++] = a[j++];
 for( i = 0;i < h-l+1; i++)
 a[l+i] = b[i];
 free(b);
 }

void mergeSort(record a[] ,int l, int h)
 {
 if(l<h)
 {
 int mid = l+ (h-l)/2;
 mergeSort(a,l,mid);
 mergeSort(a,mid+1,h);
 merge(a,l,mid,h);
 }
 }

/*void merge(int a[], int l, int mid, int h,int *c)
 {
 int i = l,j=mid+1,k=0;
 int* b = (int*)malloc(sizeof(int)*(h-l+1));
 while(i <= mid && j <= h)
 {
 if(a[i]<a[j])
 {
 (*c)++;
 b[k] = a[i];k++;i++;
 }
 else {b[k] = a[j];k++;j++;}
 }
 while(i <= mid) b[k++] = a[i++];
 while(j <= h) b[k++] = a[j++];
 for( i = 0;i < h-l+1; i++)
 a[l+i] = b[i];
 free(b);
 }

void mergeSort(int a[] ,int l, int h,int *c)
 {
 if(l<h)
 {
 int mid = l+ (h-l)/2;
 mergeSort(a,l,mid,c);
 mergeSort(a,mid+1,h,c);
 merge(a,l,mid,h,c);
 }
 }

int partition(int a[], int l, int h,int *c)
 {
 int pivot = a[l];
 int i = l;
 for(int j = l+1; j <= h; j++)
 {
 if(a[j]<pivot)
 {
 (*c)++;
 i=i+1;
 swap(&a[i],&a[j]);
 }
 }
 swap(&a[l],&a[i]);
 return i;
 }

void quickSort(int a[], int l, int h,int *c)
 {
 if(l<h)
 {
 int k = partition(a,l,h,c);
 quickSort(a,l,k-1,c);
 quickSort(a,k+1,h,c);
 }
 }

void countingSort(int a[],int n)
 {
 int max = a[0];
 for(int i=1;i<n;i++)
 {
 if(max<a[i])
 max = a[i];
 }
 int *b = (int*)malloc(sizeof(int)*(max+1));
 for(int i=0;i<=max;i++)
 b[i] = 0;
 for(int i=0;i<n;i++)
 b[a[i]]=b[a[i]]+1;
 for(int i=1;i<=max;i++)
 b[i] += b[i-1];
 int* c = (int*)malloc(sizeof(int)*n);

 for(int i=0;i<n;i++)
 c[i] = 0;
 for(int i = n-1;i>=0;i--)
 {
 c[b[a[i]]-1] = a[i];
 b[a[i]] = b[a[i]]-1;
 }
 for(int i=0;i<n;i++)
 a[i] = c[i];
 }

void heapify(int arr[], int n, int i,int *comparisons)
 {
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;

 if (left < n)
 {
 (*comparisons)++;

 if (arr[left] > arr[largest])
 largest = left;
 }
 if (right < n)
 {
 (*comparisons)++;

 if (arr[right] > arr[largest])
 largest = right;
 }
 if (largest != i)
 {
 int temp = arr[i];
 arr[i] = arr[largest];
 arr[largest] = temp;

 heapify(arr, n, largest, comparisons);
 }
 }
 int heapSort(int arr[], int n)
 {
 int comparisons = 0;
 for (int i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i, &comparisons);
 for (int i = n - 1; i > 0; i--)
 {
 int temp = arr[0];
 arr[0] = arr[i];
 arr[i] = temp;
 heapify(arr, i, 0, &comparisons);
 }

 return comparisons;
 }
 */
 void disp(char a[10][30], int n)
 {
 for(int i=0;i<n;i++)
 printf("%s\n",a[i]);
 printf("\n\n");
 }

void dispDOB(DOB d1)
 {
 printf("RegNo:%d\n",d1.regNo);
 printf("DOB:%d-%d-%d\n",d1.d.day,d1.d.month,d1.d.year);
 }

void dispPair(pair a[50],int n)
 {
 for(int i=0;i<n;i++)
 {
 printf("(%d,%s) ",a[i].a,a[i].b);
 }
 printf("\n");
 }

int main()
 {
 /*char a1[5][30];
 for(int i=0;i<5;i++)
 {
 char arr[30];
 printf("Enter the string %d:",i+1);
 scanf("%s",arr);
 copy(a1[i],arr);
 }
 insertionSort(a1,5);
 disp(a1,5);*/
 /*DOB a[5];
 for(int i=0;i<5;i++)
 {
 printf("Enter the regNO:");
 scanf("%d",&a[i].regNo);
 printf("Enter the date(dd:mm:yyyy):");
 scanf("%d:%d:%d",&(a[i].d.day),&a[i].d.month,&a[i].d.year);
 }
 quickSort(a,0,4);
 for(int i=0;i<5;i++)
 dispDOB(a[i]);*/
 pair a[50];int count =0;
 for(int i=0;i<50;i++){
 a[i].a = rand()%25;
 char s[3];
 s[0] = 'a' ;
 if(count<10){s[1] = '0'+(count%10);s[2] = '\0';count++;}
 else {s[1] = '0' + (count/10);s[2] = '0' + (count%10);s[3] = '\0';count++;}
 copy(a[i].b,s);
 }
 countingSort(a,50);
 dispPair(a,50);

 //record a[5];

 return 0;
 }