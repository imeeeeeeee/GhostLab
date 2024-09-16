import java.net.*;
import java.io.*;
import java.util.LinkedList;
import java.util.Random;
import java.lang.*;
import java.net.*;

    
 // serveur
public class serveur {

public static void emptyL(LinkedList<Socket> l){
        for(int i=0;i<l.size();i++){
            l.remove(i);
        }


    }
 

    public static void main(String[] args) {
        LinkedList<Socket> j=new LinkedList<Socket>();
        int i=0;
        try {
            ServerSocket server=new ServerSocket(4242);
             System.out.println(i);
            while(true){
                //boolean flag=true;
                while(i<2){
                    System.out.println("i avant accept "+i);
                    Socket s=server.accept();
                    System.out.println(i);
                    j.add(s);
                    i++;
                }
                i=0;
                GameLauncher gl=new GameLauncher(j);
                Thread t=new Thread(gl);
                t.start();
                emptyL(j);
            }
        } catch (Exception e) {
            System.out.println(e);
            e.printStackTrace();
        }       
    }
}