package com.zohoregister;


import java.io.IOException;
import java.io.PrintWriter;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.sql.*;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import com.zohoregister.DatabaseConnection;


@WebServlet("/search")
public class search extends HttpServlet
{
    protected void service(HttpServletRequest request,HttpServletResponse response) throws IOException
    {
    	String str = request.getParameter("search");
    	Connection con;
		try {
			con = DatabaseConnection.initializeDatabase();
			Statement stmt = con.createStatement();
			ResultSet rs;
			rs = stmt.executeQuery("select username from userdata where username like " + "'%" + str + "%'");
			PrintWriter out = response.getWriter();
			out.println("<h1>Users found : </h1><br>");
			while (rs.next())
			{
				out.println("\t\t <h3 style ='margin-left:30%'>" + rs.getString(1)+"</h3>");
			}
				
			
		} catch (ClassNotFoundException | SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
    	
    }	
		
	
	
	

}
