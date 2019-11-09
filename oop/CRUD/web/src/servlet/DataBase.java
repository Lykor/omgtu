package servlet;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Map;

import com.mysql.fabric.jdbc.FabricMySQLDriver;

import model.Flower;

public class DataBase {

    //String url="jdbc:mysql://localhost:3307/flowers?useUnicode=true&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC";
    String url="jdbc:mysql://localhost:3307/flowers";
    String name = "root";
    String pass = "root";
    Connection con;
    Statement statement;
    ResultSet result;

    public DataBase() {
        try{
            Driver driver = new FabricMySQLDriver();
            DriverManager.registerDriver(driver);

            con=DriverManager.getConnection(url,name,null);

            if(!con.isClosed()){
                System.out.println("подключен");
            }else {
                System.out.println("не подключен");
            }
            statement = con.createStatement();

        }catch (SQLException ex){
            ex.printStackTrace();
        }
    }

    public void addFlower(Flower flower) {
        try {
            statement.addBatch("INSERT INTO flowers(id,name,balance,price,rating) values("+flower.getId()
                    +",'"+flower.getName()+"',"+flower.getBalance()+","+flower.getPrice()+","+flower.getRating()+");");
            statement.executeBatch();
            statement.close();
        }catch(SQLException ex) {
            System.out.println("add not Flower");
            ex.printStackTrace();
        }
    }


    public void updateFlower(Flower flower) {
        try {
            statement.executeUpdate("UPDATE flowers SET name='"+flower.getName()+"' WHERE id="+flower.getId());
            statement.close();
        }catch(SQLException ex) {
            ex.printStackTrace();
        }
    }

    public  Flower getFlower() {

        Flower flower = new Flower();

        try {
            ResultSet resultSet = statement.executeQuery("SELECT * FROM flowers");
            while(resultSet.next()) {
                flower.setId(resultSet.getInt(1));
                flower.setName(resultSet.getString(2));
                flower.setBalance(resultSet.getInt(3));
                flower.setPrice(resultSet.getInt(4));
                flower.setRating(resultSet.getInt(5));
            }

        }catch(SQLException ex) {
            ex.printStackTrace();
        }
        return flower;
    }

    public boolean searchFlower(Flower flower) {
        boolean isHere = false;
        try {
            ResultSet resultSet = statement.executeQuery("SELECT * FROM flowers");

            while(resultSet.next()){
                if(flower.getName().equals(resultSet.getString(2))) {
                    return true;
                }
            }
        }catch(SQLException ex) {
            ex.printStackTrace();
        }
        return isHere;
    }


    public void deleteFlower(Flower flower) {
        try {
            statement.addBatch("DELETE FROM flowers WHERE id="+flower.getId());
            statement.executeBatch();
            statement.close();
        }catch(SQLException ex) {
            ex.printStackTrace();
        }
    }
}
