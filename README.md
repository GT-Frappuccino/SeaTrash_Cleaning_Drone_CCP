#_SeaTrash_Cleaning_Drone_CCP_

>>#_기본적인 라파 용어_
>>>>>디렉토리 생성
>>>>>>>mkdir 디렉토리명  mkdir -p 디렉토리명/파일명
>>>>>디렉토리 삭제 
>>>>>>>>rmdir 디렉토리명
>>>>>파일생성
>>>>>>>>touch 파일명  cat 파일명 (내용볼수있음)
>>>>>파일 삭제
>>>>>>>>>rm -rf 파일명

>>#ros (lidar)
>>>>>    ~$ roscd ydlidar/startup	      // Make the shell script to an executable
	      ~$ sudo chmod 777 ./*
	      ~$ sudo sh initenv.sh
