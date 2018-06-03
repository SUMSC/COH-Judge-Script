package main

import (
	"runtime"
	"fmt"
	"os/exec"
	"os"
	"flag"
	"strings"
	"io/ioutil"
)

func main() {
	march := runtime.GOARCH
	msys := runtime.GOOS
	var mission *string
	mission=flag.String("t","","Use -t <File Suffix> (cpp,python)")
	flag.Parse()

	if *mission==""{
		fmt.Println("Please Specify a Type! \nAborting......")
		os.Exit(1)
	}
	s:=strings.ToLower(*mission)


	if msys == "windows" {
		fmt.Println("You are using \t" + msys + "/" + march)

		if s=="cpp"||s=="c++" {
			CppWin()
		}else if s=="python" {
			PythonAll()
		}else if s=="java" {
			Java()
		}
	} else if msys == "linux" {
		//fmt.Println(os.Getenv("PATH"))
		fmt.Println("You are using \t" + msys + "/" + march)
		if s=="cpp"||s=="c++" {
			CppNix()
		}else if s=="python" {
			PythonAll()
		}else if s=="java" {
			Java()
		}
	} else if msys == "darwin" {
		fmt.Println("You are using macOSX\t" + msys + "/" + march)
		if s=="cpp"||s=="c++" {
			CppNix()
		}else if s=="python" {
			PythonAll()
		}else if s=="java" {
			Java()
		}
	} else {
		fmt.Println("Your System is not supported\nPlease Contact us at : http://www.sumsc.xin")
	}
}

func CppNix()  {
	fmt.Println("Judging C++..........")
	op :=exec.Command("g++","./Judge/judge.cpp", "-o", "./output.o")
	out,err:=op.CombinedOutput()
	if err!=nil{
		fmt.Printf("Compile Error: %v",err)
	}else{
		if out == nil {

		}
		//fmt.Println("Congratulations! Compile completed!")
	}
	op=exec.Command("./output.o")
	out,err=op.CombinedOutput()
	if err!=nil {
		fmt.Printf("Error : %v\t",err)
		os.Exit(1)
	}else {
		//fmt.Println(out)
		b, err := ioutil.ReadFile("CON")
		if err != nil {
			fmt.Print(err)
		}
		//fmt.Println(b)
		str := string(b)
		fmt.Println(str)
		defer os.Remove("output.o")
		defer os.Remove("CON")
	}
}

func CppWin()  {
	fmt.Println("Judging C++..........")
	op:=exec.Command("g++",".\\Judge\\judge.cpp","-o","./output.o ")
	out,err:=op.CombinedOutput()
	if err!=nil{
		fmt.Printf("Compile Error: %v",err)
	}else{
		if out == nil {

		}
		//fmt.Println("Congratulations! Compile completed!")
	}
	op = exec.Command("./output.o")
	out,err=op.CombinedOutput()
	if err!=nil {
		fmt.Printf("Error : %v\t",err)
		os.Exit(1)
	}else {
		//fmt.Println(out)
		b, err := ioutil.ReadFile("CON")
		if err != nil {
			fmt.Print(err)
		}
		//fmt.Println(b)
		str := string(b)
		fmt.Println(str)
		defer os.Remove("output.o")
		defer os.Remove("CON")
	}
}

func PythonAll()  {
	fmt.Println("Judging Python..........")
	op:=exec.Command("python3","./Judge/judge.py")
	out,err:=op.CombinedOutput()

	if err!=nil {
		fmt.Printf("Error : %v\t",err)
		os.Exit(1)
	}else {
		fmt.Printf("%s",out)
	}
}

func Java()  {
	fmt.Println("Judging Java..........")
	op:=exec.Command("javac","./Judge/judge.java")
	out,err:=op.CombinedOutput()
	op=exec.Command("java","Judge.judge")
	out,err=op.CombinedOutput()

	if err!=nil {
		fmt.Printf("Error : %v\t",err)
		os.Exit(1)
	}else {
		fmt.Printf("%s",out)
		defer os.Remove("./Judge/judge.class")
	}
}