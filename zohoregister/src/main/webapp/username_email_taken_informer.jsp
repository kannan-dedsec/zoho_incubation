<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
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
    
        <nav class="navbar navbar-light bg-light">
        <a class="navbar-brand" href="index.html">
        <img src="zohoico.png" width="110" height="30" class="d-inline-block align-top" alt="icon">
             Register
        </a>
        </nav>

        <form class="center_it" style="margin-top: 3% !important; margin-left: 20%;" action ="createuser" method= "post">
           <div >
           <p style ="display:inline;background-color:red;text-align: center;height:10px;width:10px"><% 
           			
           			String str = (String)request.getAttribute("string");
           			out.println("This "+str+" is already taken ..");
           		%>   </p>
           </div><br>
           
            <div class="col-md-4 mb-3">
                  <label for="validationDefault01">Name <span style="color: red;">*</span></label>
                  <input type="text" class="form-control" name ="name" id="validationDefault01" placeholder="Name" value="Mark" required>
            </div>
            <div class="col-md-4 mb-3">
                <label for="validationDefaultUsername">Username <span style="color: red;">*</span></label>
                <div class="input-group">
                  <div class="input-group-prepend">
                    <span class="input-group-text" id="inputGroupPrepend2">@</span>
                  </div>
                  <input type="text" name ="username" class="form-control" id="validationDefaultUsername" placeholder="Username" aria-describedby="inputGroupPrepend2" required>
            </div> 
            <div class="form-group" style="margin-top: 16px;">
                <label for="exampleInputEmail1">Email address <span style="color: red;">*</span></label>
                <input type="email" name ="email" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter email" required>
                <small id="emailHelp" class="form-text text-muted">We'll never share your email with anyone else.</small>
              </div>
              <div class="form-group" style="margin-top: 16px;">
                <label for="exampleInputPassword1">Password <span style="color: red;">*</span></label>
                <input name ="password" type="password" class="form-control" id="exampleInputPassword1" placeholder="Password" required>
              </div>
              <div class="form-group" style="margin-top: 16px;">
                <label for="exampleInputPassword1">Number <span style="color: red;">*</span></label>
                <input name ="number" type="tel" class="form-control" pattern="[0-9]" id="exampleInputtel1" placeholder="number" required>
              </div> 
              <button type="submit" class="btn btn-primary" style="margin-top: 20px;margin-left: 35%;">Sign up</button>
        </form>
        

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ" crossorigin="anonymous"></script>

  </body>
</html>