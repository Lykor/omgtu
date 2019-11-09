package model;

public class Flower {

    private int id;
    private String color;
    private String name;
    private int balance;
    private int price;
    private int rating;

    public Flower(String color,String name,int balance,int price,int rating){
        setColor(color);
        setName(name);
        setBalance(balance);
        setPrice(price);
        setRating(rating);
    }

    public Flower(){
        this("red","rose",43,100,95);
    }


    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
