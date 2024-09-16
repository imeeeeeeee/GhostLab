import java.net.*;
import java.io.*;
import java.util.LinkedList;
import java.util.Random;
import java.lang.*;

/**
 * GameLauncher
 */
public class GameLauncher implements Runnable{
    LinkedList<Socket> j;
    //Jeu jeu;
    public GameLauncher(LinkedList<Socket> j/*,Jeu jeu*/){
        this.j=j;
        //this.jeu=jeu;
    }

    public void run(){
        try {
            BufferedReader [] br=new BufferedReader[j.size()];
            PrintWriter [] pw=new PrintWriter[j.size()];

            for(int i=0;i<j.size();i++){
                br[i]=new BufferedReader(new InputStreamReader(j.get(i).getInputStream()));
                pw[i]=new PrintWriter(new OutputStreamWriter(j.get(i).getOutputStream()));
            }

            for(int i=0;i<j.size();i++){
                
                String r=br[i].readLine();
                String r2=br[i].readLine();
                System.out.println(r+" "+r2);

                pw[i].print("Bonjour");
                pw[i].flush();
                pw[i].print("Bonjour");
                pw[i].flush();
            }

            while(true){
                for(int i=0;i<j.size();i++){
                    String r=br[i].readLine();
                    if(r!=null) System.out.println(r);
                }
            }

        } catch (Exception e) {
            //TODO: handle exception
        }
    }
    
}