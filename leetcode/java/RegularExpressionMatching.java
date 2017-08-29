/**
 * Created by baislsl on 17-2-9.
 */
public class RegularExpressionMatching {
    public static boolean isMatch(String s, String p) {
        return myIsMatch(s,p,0,0);
    }

    public static boolean myIsMatch(String s, String p, int sIndex, int pIndex){

        char cp;
        while(pIndex < p.length()){
            cp = p.charAt(pIndex++);
            if(pIndex >= p.length() || p.charAt(pIndex) != '*'){
                if(sIndex >= s.length() || !equal(s.charAt(sIndex++),cp)) return false;
            }else{
                pIndex++;
                do{
                    if(myIsMatch(s,p,sIndex,pIndex)) return true;
                }while(sIndex < s.length() && equal(s.charAt(sIndex++),cp));
                return false;
            }
        }


        return pIndex == p.length() && sIndex == s.length();
    }

    public static boolean equal(char s,char p){
        return p == '.' || s == p;
    }

}
