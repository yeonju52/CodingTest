import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader ( new InputStreamReader(System.in));


        int t = Integer.parseInt(br.readLine());


        StringBuilder sb = new StringBuilder();
        for(int i =0;i<t;i++){

            long n = Long.parseLong(br.readLine());

            long left = 0;
            long right = 1000000000;
            long ret = 0;

            while( left <= right) {
                long mid = (left + right) /2 ;
                long sum = mid*(mid+1) /2;

                if( sum <= n) {
                    ret = mid;
                    left = mid +1;
                }else {
                    right = mid -1;
                }
            }
            sb.append(ret+"\n");
        }

        System.out.print(sb);

    }
}