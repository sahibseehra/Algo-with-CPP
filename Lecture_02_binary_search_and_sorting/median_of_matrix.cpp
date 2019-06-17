int BinarySearch(vector<vector<int> > &A,int l,int r,int n,int c){

	while(l<r)
	{
		int y=0;
		int mid=(l+r)/2,y=0;
		for(auto v:A) 
		y+=upper_bound(v.begin(),v.end(),mid)-v.begin();
		if(y>=(n*c+1)/2))
		r=mid
		else
		l=mid+1;
	}
}

int Solution::findMedian(vector<vector<int> > &A) {
    int min,max,i=INT_MIN,j=INT_MAX,n=A.size(),m=A[0].size();
    return BinarySearch(A,i,j,n,m);
}

