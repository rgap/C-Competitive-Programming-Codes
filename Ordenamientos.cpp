#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <time.h>
#include <windows.h>
using namespace std;

void InsertionSort(int *A,int i,size_t n){
    int j,key;
    for(j=i+1;j<=n;j++){
        key=*(A+j);
        i=j-1;
        while(i>=0 && *(A+i)>key){
            *(A+i+1)=*(A+i);
            i=i-1;
        }
        *(A+i+1)=key;
    }
}

void merge(int *A,int p,int q,int r){
	int i,j;
	int n1=q-p+1;
	int n2=r-q;
	int*L=new int[n1+1],*R=new int[n2+1];
	for(i=0;i<n1;i++)
		*(L+i)=*(A+p+i);	
	for(j=0;j<n2;j++)
		*(R+j)=*(A+q+j+1);
	*(L+n1)=INT_MAX;
	*(R+n2)=INT_MAX;
	i=0; 
	j=0;
	for(int k=p;k<r+1;k++){
		if(*(L+i)<=*(R+j)){
			*(A+k)=*(L+i);
			i++;
		}else{
			*(A+k)=*(R+j);
			j++;
		}
	}
	delete[]L;delete[]R;
}

void MergeSort(int *A,int p,int r){
	if(p<r){
		int q=floor((double)(p+r)/2);
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		merge(A,p,q,r);
	}
}

void BubbleSort(int *A,int i,int n){
	int j;
	for(;i<=n;i++){
		for(j=n;j>=i+1;j--){
			if(*(A+j)<*(A+j-1))
				swap(*(A+j),*(A+j-1));
		}
	}
}

//HeapSort
void Max_Heapify(int *A,int i,int size){
	int p=*(A+i);
	int q=*A;
	int l=2*i+1;//left
	int r=2*i+2;//right
	int largest;
	if(l<size && *(A+l)>*(A+i))
		largest=l;
	else
		largest=i;
	if(r<size && *(A+r)>*(A+largest))
		largest=r;
	if(largest!=i){
		swap(*(A+i),*(A+largest));
		Max_Heapify(A,largest,size);
	}
}

void Build_Max_Heap(int *A,int size){
	for(int i=size/2;i>=0;i--)
		Max_Heapify(A,i,size);
}

void HeapSort(int *A,int size){
	Build_Max_Heap(A,size);
	for(int i=size-1;i>=1;i--){
		swap(*A,*(A+i));
		Max_Heapify(A,0,i);
	}
}

//QuickSort
int Partition(int *A,int p,int r){
	int x=*(A+r);
	int i=p-1;
	for(int j=p;j<=r-1;j++){
		if(*(A+j)<=x){
			i++;
			swap(*(A+i),*(A+j));
		}
	}
	swap(*(A+i+1),*(A+r));
	return i+1;
}

void QuickSort(int *A,int p,int r){
	int q;
	if(p<r){
		q=Partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}

void CountingSort(int *A,int k,int size){
	int*C=new int[k];
	int*B=new int[size+1];
	int i;
	for(i=0;i<=k;++i) 
		C[i]=0;
	for(i=0;i<=size;++i) 
		C[A[i]]++;
	for(i=1;i<=k;++i) 
		C[i]+=C[i-1];
	for(i=size;i>=0;--i){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
	//rpta=B
}


void CountingSort(int *A,int k,int size){
	int*C=new int[k];
	int*B=new int[size+1];
	for(int i=0;i<=k;i++)
		C[i]=0;
	for(int j=0;j<=size;j++)
		C[A[j]]++;
	for(int i=1;i<=k;i++)
		C[i]+=C[i-1];
	for(int j=size;j>=0;j--){
		B[C[A[j]]-1]=A[j];
		C[A[j]]--;
	}
	//resultado B
}

//RadixSort
void RadixSort(int *A,int n,int d){
	int*B=new int[n];
	int C[10];
	int*D=new int[n];
	int i,j;
	for(j=0;j<d;++j){
		for(i=0;i<n;++i)
			D[i]=(int)(A[i]/pow(10.0,j))%10;
		for(i=0;i<10;++i) 
			C[i]=0;
		for(i=0;i<n;++i) 
			C[D[i]]++;
		for(i=1;i<10;++i) 
			C[i]+=C[i-1];
		for(i=n-1;i>=0;--i){
			B[C[D[i]]-1]=A[i];
			C[D[i]]--;
		}
		for(i=0;i<n;++i)
			A[i]=B[i];
	}
} 

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void bsum(int a[], int b[], int n) {    
	int i,carrier=0;      
	for(i=0;i<n;++i) {        
		carrier = a[i] & b[i];        
		a[i] |= b[i] | carrier;    
	} 
} 

int main(){
	LARGE_INTEGER t_ini, t_fin;

	int A[31]={99,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32};
	QueryPerformanceCounter(&t_ini);
	MergeSort(A,0,30);
	QueryPerformanceCounter(&t_fin);
	double t1=performancecounter_diff(&t_fin, &t_ini)*1000.0;
	cout<<t1<<endl;

	int B[31]={99,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32};
	QueryPerformanceCounter(&t_ini);
	InsertionSort(A,0,30);
	QueryPerformanceCounter(&t_fin);
	double t2=performancecounter_diff(&t_fin, &t_ini)*1000.0;
	cout<<t2<<endl;
	
	cout<<t1/(31*log(31.0)/log(2.0))<<endl;
	cout<<t2/(31*31)<<endl;


	int C[30]={99,31,20,24,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32};
	QueryPerformanceCounter(&t_ini);
	MergeSort(C,0,29);
	QueryPerformanceCounter(&t_fin);
	t1=performancecounter_diff(&t_fin, &t_ini)*1000.0;
	cout<<t1<<endl;

	int D[31]={99,31,20,24,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32,31,20,24,55,32};
	QueryPerformanceCounter(&t_ini);
	InsertionSort(D,0,29);
	QueryPerformanceCounter(&t_fin);
	t2=performancecounter_diff(&t_fin, &t_ini)*1000.0;
	cout<<t2<<endl;
	
	cout<<t1/(30*log(30.0)/log(2.0))<<endl;
	cout<<t2/900<<endl;

	/*
	BubbleSort(A,0,9);
	
    
	
	HeapSort(A,10);
	QuickSort(A,0,9);
	*/
	//CountingSort(A,5,7);

	system("PAUSE");
    return 0;
}
