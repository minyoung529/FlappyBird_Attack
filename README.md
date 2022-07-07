

# Flappy Bird, Attack!

###### 2학년 1학기에 C++로 개인 개발한 콘솔 게임입니다.


[클릭하면 게임 플레이 영상으로 이동합니다](https://youtu.be/SFynXBS9oRY)

<br>

## <mark>1. 서론</mark>

### 가. 게임 개요

| 장르     | 하이퍼 캐주얼                                                  |
| ------ |:-------------------------------------------------------- |
| **설명** | 기둥에 뚫린 구멍 사이로 기둥을 부딪히지 않고, 여러 아이템을 먹으며 멈춰있는 고양이를 공격하는 게임 |

* 유사 게임인 ‘Flappy Bird’에서 총을 쏘는 액션 요소를 추가해 **플레이어의 지루함을 완화**시키기 위함
* 디버프, 버프 아이템을 바탕으로 **다채로운 플레이**에, 하이퍼 캐주얼 특유의 **간단한 조작방식**의 게임을 만들기 위함
  
### 나. 게임 기획 의도
* 유사 게임인 ‘Flappy Bird’에서 총을 쏘는 액션 요소를 추가해 플레이어의 지루함	을 완화시키기 위함
* 디버프, 버프 아이템을 바탕으로 다채로운 플레이에, 하이퍼 캐주얼 특유의 간단한 	조작방식의 게임을 만들기 위함

### 다. 주요 타겟 고객
* 가벼운 캐주얼 게임을 좋아하는 플레이어
* 최고 기록을 갱신하는 것을 좋아하는 플레이어
* ‘Flappy Bird’를 재미있게 플레이해본 플레이어
  
### 라. 유사 게임 현황

<Flappy Bird>

[Flappy Bird]

![image01](https://user-images.githubusercontent.com/77655318/177682526-b4c17aae-74e2-495f-870d-5cfb2ba92606.png)





## <mark>2. 게임 설계</mark>

### 가. 게임 구조도

![flowchart](https://user-images.githubusercontent.com/77655318/177682584-c14a5b13-dce4-4e82-9939-06a32650ccf4.png)

### 나. 게임 목적

* 게임 **목적**: 자신이 달성한 최고 기록을 갱신하는 것.
  
                    자신과의 끝없는 싸움에서 이기는 것.

* **승리** 조건: 최고 기록을 갱신했을 때

* **패배** 조건: 최고 기록을 갱신하지 못했을 때
 

### 다. 게임 기능 소개

**<플레이어>**
● 날기: 스페이스바를 누르면 캐릭터가 난다.
● 총 쏘기: 왼쪽 쉬프트를 누르면 총이 나간다.

**<아이템>**
● 슬로우: 게임 속도가 일정 시간 동안 느려진다.
● 자양강장제: 총알 데미지가 올라간다
● 중력붕괴: 중력이 반대 방향으로 바뀐다.



## <mark>3. 게임 구현</mark>

### 가. UI 설명

**<시작 화면>**

![start](https://user-images.githubusercontent.com/77655318/177682644-82d7fed7-4518-4cad-a64a-7f278ba4d53e.png)

* 플래피 버드가 있는 배경

* 중앙 상단에 타이틀

    -> 플래피 버드들과 타이틀이 위아래로 움직인다.

* 중앙에 Play, Help, Quit 버튼이 순서대로 정렬

    -> 버튼 마우스 클릭은 지원하지 않음



**<도움말 화면>**

![help](https://user-images.githubusercontent.com/77655318/177682643-c7e9a09e-b350-4d7c-919b-c4598f66c9f8.png)

* 중앙 상단에 HELP

* 중앙에 게임에 대한 설명
  

**<게임 화면>**

![ingame](https://user-images.githubusercontent.com/77655318/177682640-a4be9d52-d126-47cb-a65f-39caa59d33c8.png)

* 중앙에 게임화면과 중앙 상단에 점수표

* 왼쪽에 최고 기록(HighScore)을 배치해 플레이어의 도전욕구를 자극함

* 중앙 한단에 아케이드 게임기 느낌의 인터페이스를 구성
  
  

**<승리, 패배 화면>**

![win](https://user-images.githubusercontent.com/77655318/177682633-b89e8cfe-2b58-4a93-9e1f-31fa7c0002b9.png)<br>
![fail](https://user-images.githubusercontent.com/77655318/177682638-46c71fcb-e327-4386-8454-f0c98f071c04.png)<br>

* 중앙에 ‘Fail’, ‘Congratulations’와 같은 승리, 패배 메시지

* 좌측, 우측에 해당 상황에 맞는 아스키 그림

* 중앙 하단에 상황에 맞는 문구와 현재 점수, 최고기록 점수 정렬



### 나. 조작 방법

★ => 플레이어, ● => 총알

 

![beforeJ](https://user-images.githubusercontent.com/77655318/177682629-0a31c4ee-25c2-44c0-b630-7bbb1604fa2b.png)
         -->       ![J](https://user-images.githubusercontent.com/77655318/177682628-df21577a-154c-4313-9fd9-fd995bd3f3a9.png)


* 스페이스(Space) 키를 누른 상태이면 플레이어가 2칸 점프를 한다.
  
  
  
![Bullet](https://user-images.githubusercontent.com/77655318/177682626-574fe39c-fe3f-4ba3-8d08-3f29b7fcc5e4.png)

* 왼쪽 쉬프트(Left Shift)를 누른 상태이면 총알이 발사된다.
  
  

### 다. 구현 과정

① 게임에 전체적인 **기획**을 하고 **사전 계획서**를 써서 게임을 구상했다.

② 게임이 돌아가는 전체적인 **루프**를 구현하고 **플레이어의 기능**(움직임, 총 발사)을 만들었다.

③ **기둥의 랜덤 생성**과 스코어를 구현해 게임 **승리, 패배**를 구현했다.

④ 슬로우, 자양강장제, 중력붕괴 **아이템**들의 생성과 발동 기능을 구현했다. 아이템의 이펙트나 시각적 효과, 게임 **인터페이스**를 적절하게 꾸몄다.

⑤ 메인 로비에 **게임 설명**을 추가하는 등 사용자 편의성을 개선했다. 승리, 패배시의 효과를 더 극적으로 주었다. 로비, 게임씬 등 필요한 곳에 **사운드**를 넣었다.

⑥ 게임의 버그를 찾아 고쳤고, 코드 **오류를 개선**했다. 여러 테스트를 해보고 **난이도를 조절**했다.



### 라. 기능별 구현 로직

1. **플레이어 이동**
   
   > Player Script

```cpp
if ((GetAsyncKeyState(VK_SPACE) & 0x8001) != 0)
{
	if (!isReverseGravity)
	{
		position.y -= 2;
	}

	if (isReverseGravity)
	{
		position.y += 2;
	}

	playsound(/*L"Data/Jump.wav"*/JUMP);
}
else
{
	if (!isReverseGravity)
		position.y += 1;
	else
		position.y -= 1;
}
```

* Space 키가 눌린 상태이고 중력 붕괴(중력 반대가 되는 아이템) 상태가 아니라면 플레이어의 위치는 2씩 올라가고, 반대라면 2씩 내려간다.

* Space 키가 눌리지 않은 상태이고 중력 붕괴 상태가 아니라면 플레이어의 위치는 계속 1씩 내려가고, 반대라면 1씩 올라간다.
  
  
2. **총알 발사**
   
   > Player Script
   
   ```cpp
   if ((GetAsyncKeyState(VK_LSHIFT) & 0x8001) != 0)
   {
   	int damage = (isStrong) ? 5 : 3;
   
   	Bullet* newBullet = new Bullet(position, damage, this);
   	newBullet->Init();
   	bullets.push_back(newBullet);
   
   	playsound(SHOOT);
   }
   ```
* 자양강장제 아이템을 먹은 상태라면 총알 데미지는 5, 그렇지 않다면 3이다.

* Bullet을 새로 생성해주고 생성해준 총알을 Init 함수로 초기화 해준다.

* 만든 총알을 플레이어의 총알 벡터에 넣어준다.
  
  > Player Script
  
  ```cpp
  for (int i = 0; i < bullets.size(); i++)
  {
  	if (isDead) return;
  
  	if (bullets[i])
  		bullets[i]->Update(posOnBoard);
  }
  ```

=> 벡터에 넣어준 이유: 총알을 움직이기 위해 플레이어에서 총알들의 Update 함수를 실행시키기 때문이다.

> Bullet Script

```cpp
void Bullet::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
	if (isDead)return;

	if (posOnBoard[position.y][position.x] == BLOCK_TYPE::MONSTER)
	{
		Player::AddScore(damage);
		isDead = true;
	}

	position.x += 1;

	if (position.x >= MAX_X - 1)
	{
		isDead = true;
	}
}
```

* 현재 위치가 적의 위치일 때 스코어를 총알의 데미지만큼 더해준다.

* 계속해서 오른쪽으로 이동하고, 위치가 최댓값일 때 사라지게 한다.
  
  
3. **아이템**

생성

> Item Script

```cpp
if (updateTime % 15 == 0)
{
    ITEM_TYPE randomItem = (ITEM_TYPE)(rand() % (int)ITEM_TYPE::COUNT));
    int randomY = rand() % (MAX_Y - 2);

	Item* item = new Item({ MAX_X - 1, randomY },randomItem, player);
	item->Init();

	currentObjects.push_back(item);
}
```

* GameScene의 Update를 호출한 횟수가 15의 배수일 때 새로운 아이템을 만들어준다.

* 랜덤으로 ITEM_TYPE을 설정해 랜덤 아이템이 나오도록 한다.

발동

> Item Script

```cpp
if (posOnBoard[position.y][position.x] == BLOCK_TYPE::PLAYER)
{
	isStart = true;

	switch (itemType)
	{
	case ITEM_TYPE::SLOW:
		item = new Slow();
		playsound(SLOW_ITEM);
		break;

	case ITEM_TYPE::GRAVITY:
		playsound(GRAVITY_ITEM);
		item = new Gravity();
		break;

	case ITEM_TYPE::POWERUP:
		item = new PowerUp();
		playsound(POWER);
		break;
	}

	if (item)
		item->Init();
}
```

```cpp
SceneManager* manager = new SceneManager();
SceneManager::sceneManager = manager;
Scene* gameScene = new StartScene();

manager->SetCurrentScene(gameScene);

while (true)
{
	manager->Update();

	if ((GetAsyncKeyState(VK_ESCAPE) & 0x8001) != 0)
	{
		manager->Release();
		break;
	}

	Sleep(manager->GetTimeScale());
}

return 0;

```

> Scene Manager Script

```cpp
void SceneManager::SetCurrentScene(Scene* scene)
{
	setcolor(WHITE, BLACK);
	system("cls");

	if (curScene)
	{
		curScene->ReleaseScene();
		delete curScene;
		curScene = nullptr;
	}

	curScene = scene;

	if (curScene)
		curScene->Init();
}
```

```cpp
void SceneManager::Update()
{
	curScene->Update();
}
```

* Scene Manager 전역 변수에 SetCurrentScene 함수로 현재 씬을 설정해준다.

* 메인 루프에서는 curScene의 Update만 돌려주어 해당 씬만 출력되도록 한다.



## <mark>4. 결론</mark>

### 가. 프로젝트 과정에서의 문제점

거의 C#을 사용하여 게임을 만들다가, C++로 처음부터 구조를 구상하고, 그것을 코드로 짜는 작업이 힘들었다.

그 안에서 가장 빈번하게 생긴 문제는 메모리 할당과 해제였다. 특히 직접 메모리를 해제해야 하기 때문에, 잊어버리고 메모리를 해제하지 않아 자꾸 오류가 생겼다. 또, 주소값이 없는 포인터에 접근을 해서 생기는 오류도 많았다. 이처럼 C++에 익숙하지 않아 생기는 문제들이 제법 있었다

또, 직접 구현해보니 세부 기획이 부족하다는 것을 알게 되었다. 기둥 구멍의 수, 아이템 발동 시간 등 많은 세부적인 기획이 부족했다. 또, 막연히 재밌을 것 같았던 기획이 되려 재미있는 플레이에 방해되는 경우도 있었다. 열심히 구현한 기능을 휴지통으로 버리는 일도 있어서 촘촘하지 않은 기획이 문제가 됐었다.



### 나. 느낀점 및 소감

나는 게임을 만드는 것도 좋아하지만, 사실은 그 안에 구조를 짜는 것을 좋아하는 편이다. 그래서 이 게임을 만들기 위해 C++에서 직접 루프를 만들고 구조를 구상하고, 코드로 구현하는 작업이 정말 재미있었다. 이런 구조를 구상하는 데에는 방과후(WinApi) 시간에 배워서 구현해본 구조들이 도움이 되었다.

항상 Unity 엔진을 통해 게임을 만들다가 C++로 빈 프로젝트에서 기획, 개발까지 직접 해서 게임을 만드니 C++이 조금 생소하고 어려웠지만, 정말 뿌듯하고 기억에 남는다.



## <mark>5. 참고</mark>

[GitHub - kaje11/FlappyBirdConsole: ASCII version of Flappy Bird written in C# for Windows Console](https://github.com/kaje11/FlappyBirdConsole)

해당 Github 저장소에서 텍스트로 된 플래피 버드 이미지를 가져왔습니다.

![FLappy](https://user-images.githubusercontent.com/77655318/177682872-8c264773-0829-4e15-b43b-0a0e1f4f681e.png)
