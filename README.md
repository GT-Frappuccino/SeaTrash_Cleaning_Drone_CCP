#_SeaTrash_Cleaning_Drone_CCP_

	##_기본적인 라파 용어
		디렉토리 생성
			mkdir 디렉토리명  mkdir -p 디렉토리명/파일명
		디렉토리 삭제 
			rmdir 디렉토리명
		파일생성
			touch 파일명  cat 파일명 (내용볼수있음)
		파일 삭제
			rm -rf 파일명
		python 실행
			python 파일명
		c++ 코드 컴파일
			g++ 파일명.cpp -o 파일명
			
		c++ 코드 실행
			./파일명 <-- 컴파일 먼저한 후
		
		

	##ros (lidar)
	
	      ~$ roscd ydlidar/startup	      // Make the shell script to an executable
	      ~$ sudo chmod 777 ./*
	      ~$ sudo sh initenv.sh
	  
	  라이다 실행 방법
		1.roslaunch ydlidar lidar.launch
	  	2.rosrun ydlidar ydlidar_client
		3.코드 바꾼 후 catkin_make 해주기
		
	YDLIDAR TX20 정보	
		angle distance 에서 0.00555~0.0038이 대략 1cm
                라이다를 중심으로 오른쪽 + 왼쪽 -
		
		
		
	##GPS
	
		nk-gps = u-blox 7 로 검색(gps neo 7)
		명령어 cat /dev/ttyACM0   (tty는 ls /dev/tty* 로 인식된 tty찾아서 넣으면 된다)
		gpgga 에서 구글의 KML 형식으로 변환할 때는 37 + (32.6627/60)의 좌표를 사용하여야 한다
		즉 3734.96563은 37+(34.96563/60) =37.58276 이나온다
		
		
	##MOTOR
		wpi#와 physical # 비교 - gpio readall
		
		

	
