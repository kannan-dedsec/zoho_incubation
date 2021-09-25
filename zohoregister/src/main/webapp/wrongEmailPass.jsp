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
    <!-- Image and text -->
        <nav class="navbar navbar-light bg-light">
        <a class="navbar-brand" href="index.html">
        <img src="zohoico.png" width="110" height="30" class="d-inline-block align-top" alt="icon">
             Register
        </a>
        </nav>
        
        <form class="center_it" action="logon" method="post">
        	<div >
           <p style ="display:inline;background-color:red;text-align: center;height:10px;width:10px"><% 
           			
           			String str = (String)request.getAttribute("string");
           			out.println(str);
           		%>   </p>
           </div><br>
            <div class="form-group">
              <label for="exampleInputEmail1">Email address</label>
              <input type="email" name="email" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter email">
              <br>
            </div>
            <div class="form-group">
              <label for="exampleInputPassword1">Password</label>
              <input type="password" name="password" class="form-control" id="exampleInputPassword1" placeholder="Password">
            </div>
            <!-- <div class="form-check" style="margin-top: 1px;">
              <input type="checkbox" class="form-check-input" id="exampleCheck1">
              <label class="form-check-label" for="exampleCheck1">keep me signed in</label>
            </div> -->
            <br>
            <div><a href="passchg.html">Forgot Password ? </a></div>
            <br>
            <button type="submit" class="btn btn-primary">Submit</button>
          </form>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ" crossorigin="anonymous"></script>

  </body>
</html>