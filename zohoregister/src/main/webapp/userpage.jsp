<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <title>ZOHO REGISTER</title>
    <link rel="stylesheet" href="stlysheet.css" >
    <link rel="icon" href="zohoicon.png">
  </head>
  <body>
   
	<nav class="navbar navbar-expand-lg navbar-light bg-light">
  <a class="navbar-brand" href="#"><img src="zohoico.png" width="110" height="30" class="d-inline-block align-top" alt="icon">
             Register</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>

  <div class="collapse navbar-collapse" id="navbarSupportedContent">
    <ul class="navbar-nav mr-auto">
      <li class="nav-item active">
        <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
      </li>
      <li class="nav-item">
        <a class="nav-link" onclick="myprofile()" >My profile</a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="index.html">Log out</a>
      </li>
      
    </ul>
    <form class="form-inline my-2 my-lg-0" action="search"  >
      <input style="position:absolute;width:180px;right:90px;top:12px;" name = "search" class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
      <button class="btn btn-outline-success my-2 my-sm-0" style="position:absolute;right:10px;top:12px;" type="submit">Search</button>
    </form>
  </div>
</nav>
 <%
    	int userid = (Integer)request.getAttribute("userid");
    	String name = (String)request.getAttribute("name");
    	String username = (String)request.getAttribute("username");
    	String password = (String)request.getAttribute("password");
    	String email = (String)request.getAttribute("email");
    	String number = (String)request.getAttribute("number");
    %>
    <div style="margin-left:10%;margin-top:10%">
    <h1	> User Profile</h1><br>
   	 <ul >
   	 <li>user id  =<%=userid %></li>
     <li>name     =<%=name %></li>
     <li>username =<%=username %></li>
     <li>password =<%="******" %></li>
     <li>email    =<%=email %></li>
     <li>number   =<%=number %></li>
	 </ul>
	</div> 
	<script type="text/javascript">
		function myprofile()
		{
			
			
		}
	</script>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ" crossorigin="anonymous"></script>

  </body>
</html>