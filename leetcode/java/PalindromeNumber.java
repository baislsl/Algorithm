/**
 * Created by baislsl on 17-2-9.
 */
public class PalindromeNumber {
    public static boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int count = 0,tmp = x;
        while(tmp!=0){
            count++;
            tmp /= 10;
        }

        for(int i = 0;i<count/2;i++){
            if((int)(x/Math.pow(10,i))%10 != (int)(x/(Math.pow(10,count - i - 1))%10))
                return false;
        }
        return true;

    }
}


