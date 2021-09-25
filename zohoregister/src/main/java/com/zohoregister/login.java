package com.zohoregister;


import java.io.IOException;
import java.io.PrintWriter;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
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

@WebServlet("/logon")
public class login extends HttpServlet 
{
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		
		Connection con;
		try {
			con = DatabaseConnection.initializeDatabase();
			Statement stmt = con.createStatement();
			ResultSet rs;
			int userid = 0;
			rs = stmt.executeQuery("SELECT user_id from userdata where email =" + "'" + email + "'");
			if(rs.next())
			{
				userid = Integer.parseInt(rs.getString(1));
			}
			else
			{
				request.setAttribute("string"," Incorrect Email ");
				RequestDispatcher rd = request.getRequestDispatcher("/wrongEmailPass.jsp");
				rd.forward(request, response);
			}
			
			rs = stmt.executeQuery("SELECT * from userdata where _password =" + "'" + password + "'"+" AND user_id = "+"'" + userid + "'" );
			if(rs.next())
			{
				
				userid = Integer.parseInt(rs.getString(1));
				request.setAttribute("userid",userid);
				
				String name = rs.getString(2);
				request.setAttribute("name",name);
				
				String username = rs.getString(3);
				request.setAttribute("username",username);
				
				String _password = rs.getString(4);
				request.setAttribute("password",_password);
				
				String _email = rs.getString(5);
				request.setAttribute("email",_email);
				
				String number = rs.getString(6);
				request.setAttribute("number",number);
				
				RequestDispatcher rd = request.getRequestDispatcher("/userpage.jsp");
				rd.forward(request, response);
			}
			else
			{
				request.setAttribute("string"," Incorrect password ");
				RequestDispatcher rd = request.getRequestDispatcher("/wrongEmailPass.jsp");
				rd.forward(request, response);
				
			}
			
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
	}
	

}
