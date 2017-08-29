import java.util.ArrayList;
import java.util.List;

/**
 * Created by baislsl on 17-2-4.
 */
public class test {
    public static void main(String[] args){
        ArrayList<p> list = new ArrayList<>();
        list.add(new p());
        list.add(new p());
        System.out.println(list.size());
        func(list);
        System.out.println(list.size());
    }

    static ArrayList<p> newList = new ArrayList<>();
    static void func(ArrayList<p> list){
        newList.add(list.get(0));
        newList.add(list.get(1));
        newList.remove(0);
    }
    private static class p{
        int a = 0;
        public p(){};
    }

}
