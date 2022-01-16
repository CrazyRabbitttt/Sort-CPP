#include <iostream>
using namespace std;


void merge(int *a, int start, int mid, int end) {
	int *tmp = new int[end - start + 1];		//����������ͬ��С���ݴ�����Ҳ���Կ��ٵ�[low,mid]
	int i = start;			//C���� 
	int j = mid + 1;		//B���� 
	int k = 0;				//A����
	
	while (i <= mid && j <= end) {
		//˭С�����
		tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++]; 
	} 
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= end) tmp[k++] = a[j++];
	
	//�����鷵�ص�a��
	for (int i = 0; i < k; i++) {
		a[start + i] = tmp[i];
	} 
	delete [] tmp;
	 
}

void mergeSort(int *a, int start, int end) {
	if (a == NULL || start >= end) return ;
	
	int mid = (end + start) >> 1;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);
	
	merge(a, start, mid, end);
}

int main()
{
	int i;
	int a[] = {80,30,60,40,20,60,10,50,50,50,70};
	int ilen = (sizeof(a)) / (sizeof(a[0]));

	cout << "before sort:";
	for (i=0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	mergeSort(a, 0, ilen-1);		// �鲢����(��������)
	//mergeSortDown2Up(a, ilen);			// �鲢����(��������)

	cout << "after  sort:";
	for (i=0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

}
