import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by baislsl on 17-2-17.
 */
public class GenerateParentheses {


    private List<String> myAnswer(int n, ArrayList<List<String>> data){
        if(n==0){
            List<String> ans = new ArrayList<>();
            ans.add("");
            return ans;
        }

        List<String> ans = new ArrayList<>();
        for(int i=0;i<=n-1;i++){
            for(String in : data.get(i)){
                for(String out : data.get(n - 1 - i)){
                    ans.add("(" + in + ")" + out);
                }
            }
        }

        return ans;
    }

    public List<String> generateParenthesis(int n) {

        ArrayList<List<String>> data = new ArrayList<List<String>>(n);

        for(int i=0;i<=n-1;i++){
            data.add(myAnswer(i,data));
        }
        return myAnswer(n,data);

    }
}
