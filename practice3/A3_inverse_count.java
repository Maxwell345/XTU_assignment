import java.util.Scanner;
public class A3_inverse_count {
	static int cnt;
    private static void merge(int[] arr, int start, int mid, int end) {
        int[] temp = new int[end - start + 1];
        int i = start;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cnt = cnt + mid - i + 1;
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= end) {
            temp[k++] = arr[j++];
        }
        for (k = 0; k < temp.length; k++) {
            arr[start + k] = temp[k];
        }

    }
    
    public static void divide(int[] arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        divide(arr, start, mid);
        divide(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
    
    public static int InversePairs(int[] array,int arrlength) {
        if (array.length != 0) {
            divide(array, 0, arrlength - 1);
        }
        return cnt;
    }
	public static void main(String[] args) {
		Scanner reader=new Scanner(System.in);
		int[] seq=new int[10008];
		int n,i,ans;
		while(reader.hasNext()) {
			n=reader.nextInt();
			if(n==0) break;
			for(i=0;i<n;++i) seq[i]=reader.nextInt();
			cnt=0;
			ans=InversePairs(seq, n);
			System.out.println(ans);
		}
	}

}
