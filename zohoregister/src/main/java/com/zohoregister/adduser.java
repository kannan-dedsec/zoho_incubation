package com.zohoregister;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.*;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import com.zohoregister.DatabaseConnection;


@WebServlet("/createuser")
public class adduser extends HttpServlet 
{
	public void doPost(HttpServletRequest request,HttpServletResponse respond) throws IOException, ServletException
	{
		
		String name = request.getParameter("name"); 
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String email = request.getParameter("email");
		String number = request.getParameter("number");
		int userid = 0,ok = 1;
		try {
			Connection con = DatabaseConnection.initializeDatabase();
			Statement stmt = con.createStatement();
			ResultSet rs;
			
			rs = stmt.executeQuery("SELECT username from userdata where username =" + "'" + username + "'");
			if (rs.next()) {
				ok = 0;
				request.setAttribute("string","username "+username);
				RequestDispatcher rd = request.getRequestDispatcher("/username_email_taken_informer.jsp");
				rd.forward(request, respond);
				ok = 0;
			}
			
			rs = stmt.executeQuery("SELECT email from userdata where email =" + "'" + email + "'");
			if (rs.next()) {
				ok = 0;
				request.setAttribute("string","Email "+email);
				RequestDispatcher rd = request.getRequestDispatcher("/username_email_taken_informer.jsp");
				rd.forward(request, respond);
			}
			rs = stmt.executeQuery("SELECT _number from userdata where _number =" + "'" + number + "'");
			if (rs.next()) {
				ok = 0;
				request.setAttribute("string","Number "+number);
				RequestDispatcher rd = request.getRequestDispatcher("/username_email_taken_informer.jsp");
				rd.forward(request, respond);
			}
			
			if(ok == 1)
			{
				rs = stmt.executeQuery("SELECT MAX(user_id)  FROM userdata");
				if (rs.next()) {
					userid = Integer.parseInt(rs.getString(1));
					userid++;
				}
				int t = stmt.executeUpdate("INSERT into userdata VALUES(" + userid + "," + "'" + name + "'" + "," + "'" + username + "'" + ","+ "'" + password + "'" + "," + "'" + email + "'" + "," + "'" + number + "'" + ")");
				RequestDispatcher rd = request.getRequestDispatcher("signupsuc.html");
		        rd.forward(request, respond);
			}
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		
		
//		PrintWriter out = respond.getWriter();
//		out.print("<h1>hello</h1>name = "+name+"\nusername = "+username+"\npassword = "+password);
	}

}
