const exec = require("child_process").exec;


exec("./example",(err,stdout,stderr)=>{
    if(err){
        console.log(err);
    }else if(stdout){
        console.log(stdout);
    }else{
        console.log(stderr);
    }
});