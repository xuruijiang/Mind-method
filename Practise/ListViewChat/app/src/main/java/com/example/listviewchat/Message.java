package com.example.listviewchat;

public class Message {
    private String content;
    private Boolean sended;

    public Message(){

    }
    public Message(String content,boolean sended){
        this.content = content;
        this.sended = sended;
    }
    public String getContent(){
        return content;
    }
    public void setContent(String content){
        this.content = content;
    }
    public boolean isSended(){
        return sended;
    }
    public void setSended(boolean sended){
        this.sended = sended;
    }
}
