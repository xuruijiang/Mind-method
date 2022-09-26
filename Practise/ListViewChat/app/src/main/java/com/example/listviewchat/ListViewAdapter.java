package com.example.listviewchat;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.List;

public class ListViewAdapter extends BaseAdapter {
    private final int TYPE_SEND = 0;
    private final int TYPE_ACCEPT = 1;

    private LayoutInflater inflater;
    private List<Message> messages;

    public ListViewAdapter(Context context,List<Message> messages){
        inflater = LayoutInflater.from(context);
        this.messages = messages;
    }

    @Override
    public int getCount() {
        return messages.size();
    }

    @Override
    public Object getItem(int position) {
        return messages.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public int getViewTypeCount() {
        return TYPE_ACCEPT+1;
    }

    @Override
    public int getItemViewType(int position) {
        if (messages.get(position).isSended()){
            return TYPE_SEND;
        }
        return TYPE_ACCEPT;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        int type = getItemViewType(position);
        Message message = messages.get(position);

        ViewHolder viewHolder;
        if (convertView == null){
            viewHolder = new ViewHolder();
            if (type == TYPE_SEND){
                convertView = inflater.inflate(R.layout.activity_send,null);
            } else if (type == TYPE_ACCEPT){
                convertView = inflater.inflate(R.layout.activity_accept,null);
            }

            viewHolder.tvContent = (TextView)convertView.findViewById(R.id.tv_content);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        viewHolder.tvContent.setText(message.getContent());
        return convertView;
    }

    private class ViewHolder{
        private TextView tvContent;
    }
}
