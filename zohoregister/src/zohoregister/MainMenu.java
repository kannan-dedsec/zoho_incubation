// sign in application to store user account in database

package zohoregister;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.*;

public class MainMenu {

	public static void main(String[] args) throws Exception // Home page
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int oper;
		int loop = 1;

		do {
			linePrint();
			loop = 0;
			System.out.print("\nZOHO REGISTER" + "\n\t");
			System.out.print("\n\t" + "1. sign-in" + "\n\t" + "2. sign-up" + "\n\t" + "3. EXIT" + "\n\n\t\t");
			// Runtime.getRuntime().exec("cls");

			oper = Integer.parseInt(input.readLine());

			switch (oper) {
			case 1:
				credentialCheck();
				break;
			case 2:
				signUp();
				break;
			case 3:
				System.exit(0);
				break;
			default:
				System.out.println("\n\n ENTERED THE WRONG INPUT !!");
			}
		} while (loop == 1);

	}

	public static void linePrint() // will print a line length of 100
	{

		for (int i = 0; i < 100; i++) {
			System.out.print("-");
		}

	}

	public static void signIn(String username) throws Exception // sign in home page
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int oper;
		int loop;
		String username1, email;
		do {
			loop = 0;
			linePrint();
			System.out.println("\nZOHO REGISTER ");
			System.out.println(
					"\t 1. My Profile \n\t 2. search users \n\t 3. change password \n\t 4. log out \n\t 5. exit");
			oper = Integer.parseInt(input.readLine());
			switch (oper) {
			case 1:
				linePrint();
				System.out.println("\nZOHO REGISTER ");
				profile(username);
				loop = 1;
				break;
			case 2:
				search();
				loop = 1;
				break;
			case 3:
				System.out.print("\n\t Enter your username : ");
				username1 = input.readLine();
				System.out.print("\n\t Enter your email : ");
				email = input.readLine();
				forgotpass(username1, email);
				loop = 1;
				break;
			case 4:
				main(null);
				break;
			case 5:
				System.exit(0);
				break;
			default:
				System.out.println("\n\t wrong input !!!");
				loop = 1;
			}
		} while (loop == 1);

	}

	public static void credentialCheck() throws Exception // checks for User name and password if matches the database
															// it will execute sign in function
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String username, password, email;
		int oper, loop = 0;

		do {
			loop = 0;
			linePrint();
			System.out.print("\nZOHO REGISTER" + "\n\t");
			System.out.print("\n\t" + "Enter the username : ");
			username = input.readLine();
			System.out.print("\n\t" + "Enter the password : ");
			password = input.readLine();

			try {
				Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/zohoregister", "root",
						"123321");
				Statement stmt = con.createStatement();
				ResultSet rs = stmt.executeQuery("select username,_password from userdata where username =" + '"'
						+ username + '"' + " AND " + "_password =" + '"' + password + '"');

				if (rs.next()) {
					signIn(username);
				} else {
					loop = 0;
					System.out.print("\n\t" + "Wrong username or password !!\n\t"
							+ "\n\t 1. try again \n\t 2. forgot password \n\t 3. Main menu \n\t 4. Exit");
					oper = Integer.parseInt(input.readLine());
					switch (oper) {
					case 1:
						loop = 1;
						break;
					case 2:
						System.out.print("\n\t Enter your username : ");
						username = input.readLine();
						System.out.print("\n\t Enter your email : ");
						email = input.readLine();
						forgotpass(username, email);
						loop = 1;
						break;
					case 3:
						main(null);
						break;
					case 4:
						System.exit(0);
					default:
						System.out.println("\n\t wrong input !!!");
						loop = 1;
						break;
					}
				}
				con.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} while (loop == 1);

	}

	public static void forgotpass(String username, String email) throws Exception // will reset the password for the
																					// user name and email passed in the
																					// argument
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String newpass;

		try {
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/zohoregister", "root", "123321");
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery("select username,email from userdata where username =" + '"' + username
					+ '"' + "AND" + " email = " + '"' + email + '"');
			@SuppressWarnings("unused")
			int rs1;
			if (rs.next()) {
				System.out.print("\n\t" + "enter new password : ");
				newpass = input.readLine();
				rs1 = stmt.executeUpdate("update userdata set _password =" + '"' + newpass + '"' + " where username ="
						+ '"' + username + '"');
			} else {
				System.out.print("\n\t wrong username or email \n\t press any key to get back ...");
			}
			con.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

	public static void search() throws Exception // partial string search function will search the substring of user
													// name entered is in the database
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		linePrint();
		String SearchString;
		System.out.println("\n ZOHO REGISTER");
		System.out.print("\n\t Search : ");
		SearchString = input.readLine();
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/zohoregister", "root", "123321");
		Statement stmt = con.createStatement();
		ResultSet rs = stmt
				.executeQuery("select username from userdata where username like " + "'%" + SearchString + "%'");
		System.out.print("\n");
		while (rs.next())
			System.out.println("\t\t " + rs.getString(1));

		con.close();
	}

	public static void signUp() throws Exception // create a new table in database in the format of (user id, name, user
													// name, password, email, number)
	{
		String username, password, name, email, number;
		int userid = 0, loop = 0;
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

		try {
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/zohoregister", "root", "123321");
			Statement stmt = con.createStatement();
			ResultSet rs;
			rs = stmt.executeQuery("SELECT MAX(user_id)  FROM userdata");
			if (rs.next()) {
				userid = Integer.parseInt(rs.getString(1));
				userid++;
			}

			linePrint();
			System.out.println("\nZOHO REGISTER ");
			System.out.println("\n\t\t\t Enter Your Credentials \n");
			System.out.print("\n\t Enter the name : ");
			name = input.readLine();

			do {
				loop = 0;
				System.out.print("\n\t Enter the username : ");
				username = input.readLine();
				rs = stmt.executeQuery("SELECT username from userdata where username =" + "'" + username + "'");
				if (rs.next()) {
					System.out.println("\t This username is already taken ");
					loop = 1;
				}
			} while (loop == 1);

			System.out.print("\n\t Enter the password : ");
			password = input.readLine();

			do {
				loop = 0;
				System.out.print("\n\t Enter the Email : ");
				email = input.readLine();
				rs = stmt.executeQuery("SELECT email from userdata where email =" + "'" + email + "'");
				if (rs.next()) {
					System.out.println("\t This email is already registered ");
					loop = 1;
				}
			} while (loop == 1);

			do {
				loop = 0;
				System.out.print("\n\t Enter the Mobile Number : ");
				number = input.readLine();
				rs = stmt.executeQuery("SELECT _number from userdata where _number =" + "'" + number + "'");
				if (rs.next()) {
					System.out.println("\n\t This Number is already Registered ");
					loop = 1;
				}
			} while (loop == 1);

			@SuppressWarnings("unused")
			int t = stmt.executeUpdate(
					"INSERT into userdata VALUES(" + userid + "," + "'" + name + "'" + "," + "'" + username + "'" + ","
							+ "'" + password + "'" + "," + "'" + email + "'" + "," + "'" + number + "'" + ")");
			System.out.println(" \n\t\t you have succesfully registered \n\t\t Please Sign in");
			credentialCheck();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static void profile(String username) // will print the particular row in the database in the match of a
												// string as user name
	{
		try {
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/zohoregister", "root", "123321");
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery("select * from userdata where username =" + '"' + username + '"');
			while (rs.next())
				System.out.println("\n\t user ID = " + rs.getInt(1) + "\n\t Name  = " + rs.getString(2)
						+ "\n\t Username = " + rs.getString(3) + "\n\t Password = " + "*****" + "\n\t Email = "
						+ rs.getString(5) + "\n\t Number = " + rs.getString(6));
			con.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
