#define myQuickSort 1

template<typename NumberType, typename ArrType>
void bubblesort(ArrType arr[], NumberType first, NumberType last)
{
	//氣泡排序法之副程式
	ArrType temp;
	NumberType i=0,j=0;
	for (i=last; i>first; i--)
	{
		//sp=1;
		for (j =first; j <i; j++)
		{
			if (arr[j] > arr[j+1])
			{  
				//兩數交換位置
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
};

//快速排序 pivot 取平均

template<typename NumberType, typename ArrType>
NumberType split2(ArrType arr[], NumberType first, NumberType last)
{
	ArrType pivot, temp;

	//取pivot，依條件取 (first + last +middle)/3
	//因為在外層已判斷只有二個就不會進來split所以直接取 first 和 last middle
	int pos=(first+last)/2;
	pivot= (arr[first] + arr[last] + arr[pos])/3;


	//NumberType left=first, right=last;
	NumberType i=first-1, j=last+1;

	while(true)
	{
		while(i<last && arr[++i]<pivot);
		while(j>i && arr[--j]>pivot);
		if(i>=j)break;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		//for(int i=0;i<10;i++) cout<<arr[i] << " " ;
		//cout<<endl;
	}
	temp=arr[i];
	arr[i]=arr[last];
	arr[last]=temp;

	//for(int i=0;i<10;i++) cout<<arr[i] << " " ;
	//cout<<endl;

	return i;
	
}



template <typename NumberType,typename ArrType>
void QuickSort2(ArrType arr[], NumberType left, NumberType right)
{
	//NumberType i,j;
	ArrType temp;

	NumberType pos;
	if(right>left)
	{
		//顯示排序結果
		//for(int i=0;i<10;i++) cout<<arr[i] << " " ;
		//cout<<endl;
		if(left+1==right && arr[left] > arr[right])
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;		
		}
		//if(right-left<=7)
		//{
		//	bubblesort(arr,left,right);
		//}
		else
		{
			pos = split2(arr, left,right);
			QuickSort2(arr,left,pos-1);
			QuickSort2(arr,pos,right);
		}
	}
}



//快速排序 pivot 取 last
template<typename NumberType, typename ArrType>
NumberType split(ArrType arr[], NumberType first, NumberType last)
{
	ArrType pivot=arr[last], temp;
	//NumberType left=first, right=last;
	NumberType i=first-1, j=last;

	if (last>first)
	{
		while(true)
		{
			while(arr[++i]<pivot);
			while(arr[--j]>pivot);
			if(i>=j)break;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			//for(int i=0;i<10;i++) cout<<arr[i] << " " ;
			//cout<<endl;
		}
		temp=arr[i];
		arr[i]=arr[last];
		arr[last]=temp;

		//for(int i=0;i<10;i++) cout<<arr[i] << " " ;
		//cout<<endl;

		return i;
	}
}

template <typename NumberType,typename ArrType>
void QuickSort(ArrType arr[], NumberType left, NumberType right)
{
	NumberType i,j;
	ArrType pivot,temp;

	NumberType pos;
	if(right>left)
	{
		//顯示排序結果
		//for(int i=0;i<10;i++) cout<<arr[i] << " " ;
		//cout<<endl;
		if(left+1==right && arr[left] > arr[right])
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
		}
		else
		{
			pos = split(arr, left,right);
			QuickSort(arr,left,pos-1);
			QuickSort(arr,pos+1,right);
		}
	}
}



//快速排序 pivot 沒分出另一個函數
template <typename NumberType,typename ArrType>
void QuickSort1(ArrType arr[], NumberType left, NumberType right)
{
	NumberType i,j;
	ArrType pivot,temp;
	if(right>left)
	{
		if(left+1==right && arr[left]>pivot)
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;	
		}
		else
		{
			pivot=arr[right];
			//pivot=arr[left];
			i=left-1;
			j=right;
			while(true)
			{
				while(arr[++i]<pivot);
				while(arr[--j]>pivot);
				if(i>=j)break;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;

			QuickSort(arr,left,i-1);
			QuickSort(arr,i+1,right);
		}
	}
}
