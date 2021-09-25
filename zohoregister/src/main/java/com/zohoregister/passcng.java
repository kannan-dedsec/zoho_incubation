package com.zohoregister;

import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.sql.*;

@WebServlet("/passcng")

public class passcng extends HttpServlet
{
	
	public void doPost(HttpServletRequest request,HttpServletResponse response) throws IOException, ServletException
	{
		
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		Connection con;
		try {
			con = DatabaseConnection.initializeDatabase();
			Statement stmt = con.createStatement();
			ResultSet rs;
			
			rs = stmt.executeQuery("Select _password from userdata where email ='"+email+"'");
			if(rs.next())
			{
				int t = stmt.executeUpdate("update userdata set _password='"+password+"'"+" where email ="+"'"+email+"'");
				PrintWriter out = response.getWriter();
				out.println("<h1 style:'margin-left:40%;margin-top:10%'> password changed</h1>");
				out.println("<h3><a href='http://localhost:8080/zohoregister/index.html'>Sign-in</a><h3>");
			}
			else
			{
				request.setAttribute("string"," Incorrect Email ");
				RequestDispatcher rd = request.getRequestDispatcher("/wrongEmailPass.jsp");
				rd.forward(request, response);
			}
			
		} catch (ClassNotFoundException | SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
