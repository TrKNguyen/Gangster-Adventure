#include "Pic.h"

SDL_Window *window = NULL;

SDL_Renderer *render = NULL;

SDL_Event e;

Mix_Chunk *AnChuot = NULL;

bool ChoiLai = false;

const int DELTA = 153;

// begin menu
Pic AnhNenChinh;

Pic Idle;

Pic DongMoDau;

TTF_Font *PhongChuMenu;

SDL_Color MenuMauChu =
	{
		112, 38, 50};

const std::string
	AnhNen[3] =
		{
			"img/AnhNen/background_2.png",
			"img/AnhNen/background_1.png",

			"img/AnhNen/background_0.png",
};

void LoadHinhAnhMenu()
{

	AnhNenChinh.loadIMG(AnhNen[0], render, 1000, 563, 1);

	Idle.loadIMG("img/AnhNen/Human.png", render, 50, 100, 1);

	PhongChuMenu = TTF_OpenFont("font/Pacifico.ttf", 70);
}

bool start_game()
{

	if (ChoiLai == true)
		return 1;

	PhongChuMenu = TTF_OpenFont("font/Pacifico.ttf", 50);

	DongMoDau.loadText("Press space", render, 250, 125, PhongChuMenu,
					   MenuMauChu);

	PhongChuMenu = TTF_OpenFont("font/Pacifico.ttf", 70);

	bool ThoatGame = false;

	while (!ThoatGame)

	{

		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

		SDL_RenderClear(render);

		AnhNenChinh.Render(render, 0, 0, NULL);

		Idle.Render(render, 485, 300, NULL);

		DongMoDau.Render(render, 390, 440, NULL);

		SDL_Rect rect_1 =
			{
				400, 200, 200, 75};

		SDL_Rect rect_2 =
			{
				400, 300, 200, 75};

		SDL_RenderPresent(render);

		while (SDL_PollEvent(&e) != 0)

		{

			if (e.type == SDL_QUIT)
				return 0;

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)

			{

				Mix_PlayChannel(-1, AnChuot, 0);

				return 1;
			}
		}
	}

	return 1;
}

bool XuLiMenu()
{

	LoadHinhAnhMenu();

	if (!start_game())
		return 0;

	return 1;
}

void GiaiPhongBoNhoMenu()
{

	DongMoDau.Free();

	TTF_CloseFont(PhongChuMenu);

	PhongChuMenu = NULL;
}

// end menu

// begin play
Pic AnhNenPlay;

Pic NhanVatChinh;

Pic NhanVatChinh_Truot;

Pic CHUOT1;

Pic CHIM1;

Pic CHUOT2;

Pic CHIM2;

Pic ThuaGame;

Pic DiemSoText;

Pic Text;

Pic HighScoreText;

TTF_Font *DiemSoFont;

TTF_Font *Font;

Mix_Music *gMusic = NULL;

Mix_Chunk *gNhayAmThanh = NULL;

Mix_Chunk *gTruotAmThanh = NULL;

Mix_Chunk *gTangCap = NULL;

Mix_Chunk *gThuaGame = NULL;

int
	j = 0;

int
	i = 0;

int
	DiemSo = 0;

bool Nhay = false;

bool CheckTruot = false;

int
	type[1005];

int
	dis[1005];

int
	frame[1005];

int
	x[1005];

const std::string
	Truot = {
		"img/Truot/lie.png",
};

const std::string
	Chay = {
		"img/Chay/Human_run.png",
};

const std::string
	ChuongNgaiVat[4] =
		{
			"img/ChuongNgaiVat/rat1.png",
			"img/ChuongNgaiVat/rat2.png",

			"img/ChuongNgaiVat/bird1.png",
			"img/ChuongNgaiVat/bird2.png",
};

void loadMedia()
{

	// load AnhNenPlay;
	NhanVatChinh.loadIMG(Chay, render, 120 * 6, 120, 6);

	NhanVatChinh_Truot.loadIMG(Truot, render, 120, 30, 1);

	CHUOT1.loadIMG(ChuongNgaiVat[0], render, 100 * 4, 30, 4);

	CHIM1.loadIMG(ChuongNgaiVat[2], render, 75 * 6, 75, 6);

	CHUOT2.loadIMG(ChuongNgaiVat[1], render, 100 * 4, 30, 4);

	CHIM2.loadIMG(ChuongNgaiVat[3], render, 75 * 6, 75, 6);

	AnhNenPlay.loadIMG(AnhNen[1], render, 1000, 563, 1);

	// Handle animation
	NhanVatChinh.Handle_Clip();

	CHUOT1.Handle_Clip();

	CHIM1.Handle_Clip();

	CHUOT2.Handle_Clip();

	CHIM2.Handle_Clip();

	// Load music
	gMusic = Mix_LoadMUS("sound/NhacNenGuitar.mp3");

	// Load sound effects
	gNhayAmThanh = Mix_LoadWAV("sound/Nhay.wav");

	gTruotAmThanh = Mix_LoadWAV("sound/Truot.wav");

	gTangCap = Mix_LoadWAV("Sound/TangCap.mp3");

	gThuaGame = Mix_LoadWAV("Sound/ThuaGame.wav");

	Mix_PlayMusic(gMusic, -1);
}

void

Play()
{

	int
		NhanVatChinh_frame = 0;

	int
		DELAY = 30;

	int
		ThanhCuon = 0;

	int
		j = 0;

	int
		i = 0;

	int
		y = -DELTA;

	int
		z = 17;

	std::ifstream file("HighScore.txt");

	int
		highScore;

	file >> highScore;

	bool ThoatGame = false;

	bool DungLai = false;

	type[0] = 0;

	dis[0] = 1000;

	frame[0] = 0;

	x[0] = 0;

	loadMedia();

	while (!ThoatGame)

	{

		// Scrolling map
		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

		SDL_RenderClear(render);

		SDL_Rect rect_data_1 =
			{
				ThanhCuon, 0, 1000 - ThanhCuon, 563};

		SDL_Rect rect_data_2 =
			{
				0, 0, ThanhCuon, 563};

		AnhNenPlay.Render(render, 0, 0, &rect_data_1);

		AnhNenPlay.Render(render, 1000 - ThanhCuon, 0, &rect_data_2);

		if (DungLai == false)

		{

			ThanhCuon += 5;

			if (ThanhCuon == 1000)
				ThanhCuon = 0;
		}

		// DiemSo
		if ((DiemSo / 15) % 100 == 0 && (DiemSo / 15) != 0 && DiemSo % 15 == 0)

		{

			Mix_PlayChannel(-1, gTangCap, 0);

			DiemSoFont = TTF_OpenFont("font/Pacifico.ttf", 60);

			SDL_Color DiemSoColor =
				{
					255, 255, 255};

			std::string text = "Score: " + convertItoStr(DiemSo / 15);

			DiemSoText.loadText(text, render, 200, 50, DiemSoFont, DiemSoColor);

			DiemSoText.Render(render, 0, 40, NULL);
		}

		else

		{

			DiemSoFont = TTF_OpenFont("font/Pacifico.ttf", 20);

			SDL_Color DiemSoColor =
				{
					255, 255, 255};

			std::string text = "Score: " + convertItoStr(DiemSo / 15);

			DiemSoText.loadText(text, render, 100, 30, DiemSoFont, DiemSoColor);

			DiemSoText.Render(render, 0, 40, NULL);
		}

		if ((DiemSo / 15) <= highScore)

		{

			DiemSoFont = TTF_OpenFont("font/Pacifico.ttf", 30);

			SDL_Color DiemSoColor =
				{
					255, 255, 255};

			std::string text = "High Score: " + convertItoStr(highScore);

			HighScoreText.loadText(text, render, 150, 30, DiemSoFont,
								   DiemSoColor);

			HighScoreText.Render(render, 0, 0, NULL);
		}

		else

		{

			DiemSoFont = TTF_OpenFont("font/Pacifico.ttf", 30);

			SDL_Color DiemSoColor =
				{
					255, 255, 255};

			std::string text = "High Score: " + convertItoStr(DiemSo / 15);

			HighScoreText.loadText(text, render, 150, 30, DiemSoFont,
								   DiemSoColor);

			HighScoreText.Render(render, 0, 0, NULL);
		}

		if (DungLai == false)
			DiemSo += 5;

		// Handle animation for NhanVatChinh
		if (CheckTruot == false)

		{

			SDL_Rect *NhanVatChinh_CurrentClip =
				&NhanVatChinh.clip[NhanVatChinh_frame];

			NhanVatChinh.Render(render, 200, 390 - DELTA + abs(y),
								NhanVatChinh_CurrentClip);
		}

		else

		{

			NhanVatChinh_Truot.Render(render, 200, 480, NULL);
		}

		if (Nhay == false)

		{

			if (DungLai == false)

			{

				++NhanVatChinh_frame;

				if (NhanVatChinh_frame ==
					NhanVatChinh.WALKING_ANIMATION_FRAMES)
					NhanVatChinh_frame = 0;
			}
		}

		// Handle animation for impediment
		PositionRect rect1;

		PositionRect rect2;

		if (CheckTruot == false)

			rect1.setup(200, 390 - DELTA + abs(y), 200 + 120 - 1,
						390 - DELTA + abs(y) + 120 - 1);

		else

			rect1.setup(200, 480, 200 + 120 - 1, 480 + 30 - 1);

		for (int k = i; k <= j; ++k)

		{

			switch (type[k])

			{

			case 0:

			{

				SDL_Rect *CHUOT1_CurrentClip = &CHUOT1.clip[frame[k]];

				CHUOT1.Render(render, dis[k] - x[k], 479,
							  CHUOT1_CurrentClip);

				rect2.setup(dis[k] - x[k], 479, dis[k] - x[k] + 100 - 1,
							479 + 30 - 1);

				if (!UnCollision(rect1, rect2))

				{

					// Pause the music
					Mix_PauseMusic();

					ThoatGame = true;
				}

				if (DungLai == false)

				{

					++frame[k];

					if (frame[k] >= CHUOT1.WALKING_ANIMATION_FRAMES)
						frame[k] = 0;
				}

				break;
			}

			case 1:

			{

				SDL_Rect *CHUOT2_CurrentClip = &CHUOT2.clip[frame[k]];

				CHUOT2.Render(render, dis[k] - x[k], 479,
							  CHUOT2_CurrentClip);

				rect2.setup(dis[k] - x[k], 479, dis[k] - x[k] + 100 - 1,
							479 + 30 - 1);

				if (!UnCollision(rect1, rect2))

				{

					// Pause the music
					Mix_PauseMusic();

					ThoatGame = true;
				}

				if (DungLai == false)

				{

					++frame[k];

					if (frame[k] >= CHUOT2.WALKING_ANIMATION_FRAMES)
						frame[k] = 0;
				}

				break;
			}

			case 2:

			{

				SDL_Rect *CHIM1_CurrentClip = &CHIM1.clip[frame[k]];

				CHIM1.Render(render, dis[k] - x[k], 390, CHIM1_CurrentClip);

				rect2.setup(dis[k] - x[k], 390, dis[k] - x[k] + 75 - 1,
							390 + 75 - 1);

				if (!UnCollision(rect1, rect2))

				{

					// Pause the music
					Mix_PauseMusic();

					ThoatGame = true;
				}

				if (DungLai == false)

				{

					++frame[k];

					if (frame[k] >= CHIM1.WALKING_ANIMATION_FRAMES)
						frame[k] = 0;
				}

				break;
			}

			case 3:

			{

				SDL_Rect *CHIM2_CurrentClip = &CHIM2.clip[frame[k]];

				CHIM2.Render(render, dis[k] - x[k], 390, CHIM2_CurrentClip);

				rect2.setup(dis[k] - x[k], 390, dis[k] - x[k] + 75 - 1,
							390 + 75 - 1);

				if (!UnCollision(rect1, rect2))

				{

					// Pause the music
					Mix_PauseMusic();

					ThoatGame = true;
				}

				if (DungLai == false)

				{

					++frame[k];

					if (frame[k] >= CHIM2.WALKING_ANIMATION_FRAMES)
						frame[k] = 0;
				}

				break;
			}
			}

			if (ThoatGame == true)
				break;

			if (DungLai == false)
				x[k] += 10;
		}

		// xu ly phan sinh ra chuong ngai vat
		if (dis[i] - x[i] < 0)
			++i;

		if (dis[j] - x[j] <= 1000 && dis[j] - x[j] + 10 >= 1000)

		{

			++j;

			type[j] = rand() % 4;

			dis[j] = rand() % 201 + 1600;

			frame[j] = 0;

			x[j] = 0;
		}

		SDL_RenderPresent(render);

		if (ThoatGame == false)

		{

			// xu ly tang do kho cho game
			if ((DiemSo / 15) % 100 == 0 && (DiemSo / 15) != 0 && DiemSo % 15 == 0)

				if (DELAY >= 10)
					DELAY -= 2;

			SDL_Delay(DELAY);
		}

		else

		{

			// ThuaGame
			SDL_Delay(200);

			break;
		}

		if (SDL_PollEvent(&e) != 0)

		{

			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN))

			{

				// Stop the music
				Mix_HaltMusic();

				ThoatGame = true;
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP)

			{

				if (Nhay == false)

				{

					Nhay = true;

					y = -DELTA;

					z = 17;

					NhanVatChinh_frame = 4;

					// Play sound effect
					Mix_PlayChannel(-1, gNhayAmThanh, 0);
				}
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN)

			{

				if (CheckTruot == false)

				{

					CheckTruot = true;

					Nhay = false;

					y = -DELTA;

					z = 17;

					Mix_PlayChannel(-1, gTruotAmThanh, 0);
				}
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)

			{

				Mix_PlayChannel(-1, AnChuot, 0);

				if (DungLai == false)

				{

					Mix_PauseMusic();

					DungLai = true;
				}

				else

				{

					Mix_ResumeMusic();

					DungLai = false;
				}
			}

			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_DOWN)

			{

				CheckTruot = false;
			}
		}

		if (Nhay == true)

		{

			if (DungLai == false)

			{

				y += abs(z);

				--z;

				if (y == DELTA)

				{

					Nhay = false;

					y = -DELTA;
				}

				if (y == 0)

				{

					NhanVatChinh_frame = 5;
				}
			}
		}
	}

	if (DiemSo / 15 > highScore)

	{

		std::ofstream out("HighScore.txt");

		out << DiemSo / 15;
	}
}

void End()
{

	// Load font and text
	SDL_Color MauChu =
		{
			0, 0, 0};

	Font = TTF_OpenFont("font/Pacifico.ttf", 50);

	Text.loadText("Press space to replay", render, 250, 125, Font, MauChu);

	// Load high score from file
	std::ifstream file("HighScore.txt");

	int
		highScore;

	file >> highScore;

	// Load background image
	AnhNenPlay.loadIMG(AnhNen[2], render, 1000, 563, 1);

	// Play game over sound effect once
	bool ThoatGame = false;

	bool ok = true;

	while (!ThoatGame)

	{

		if (ok == true)

		{

			Mix_PlayChannel(-1, gThuaGame, 0);

			ok = false;
		}

		// Render elements on screen
		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

		SDL_RenderClear(render);

		AnhNenPlay.Render(render, 0, 0, NULL);

		ThuaGame.loadIMG("img/Thua/gameover.png", render, 300, 300, 1);

		ThuaGame.Render(render, 350, 0, NULL);

		Text.Render(render, 370, 350, NULL);

		SDL_RenderPresent(render);

		// Handle events
		while (SDL_PollEvent(&e) != 0)

		{

			if (e.type == SDL_QUIT)

			{

				ThoatGame = true;

				ChoiLai = false;
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)

			{

				ChoiLai = true;

				Mix_PlayChannel(-1, AnChuot, 0);

				ThoatGame = true;
			}
		}
	}
}

void GiaiPhongBoNhoPlay()
{

	AnhNenPlay.Free();

	NhanVatChinh.Free();

	NhanVatChinh_Truot.Free();

	CHUOT1.Free();

	CHIM1.Free();

	CHUOT2.Free();

	CHIM2.Free();

	ThuaGame.Free();

	DiemSoText.Free();

	HighScoreText.Free();

	TTF_CloseFont(DiemSoFont);

	Mix_FreeMusic(gMusic);

	Mix_FreeChunk(gNhayAmThanh);

	Mix_FreeChunk(gTruotAmThanh);

	Mix_FreeChunk(gTangCap);

	Mix_FreeChunk(gThuaGame);

	gMusic = NULL;

	gNhayAmThanh = NULL;

	gTruotAmThanh = NULL;

	gTangCap = NULL;

	gThuaGame = NULL;

	j = 0;

	i = 0;

	DiemSo = 0;

	Nhay = false;

	CheckTruot = false;
}

// end play

void init()
{

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)

	{

		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}

	else

	{

		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))

		{

			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		window =
			SDL_CreateWindow("Test Game", SDL_WINDOWPOS_UNDEFINED,
							 SDL_WINDOWPOS_UNDEFINED, 1000, 563,
							 SDL_WINDOW_SHOWN);

		if (window == NULL)

		{

			printf("Window could not be created! SDL Error: %s\n",
				   SDL_GetError());
		}

		else

		{

			// Create renderer for window
			render =
				SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (render == NULL)

			{

				printf("Renderer could not be created! SDL Error: %s\n",
					   SDL_GetError());
			}

			else

			{

				// Initialize renderer color
				SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int
					imgFlags = IMG_INIT_PNG;

				if (!(IMG_Init(imgFlags) & imgFlags))

				{

					printf("SDL_image could not initialize! SDL_image Error: %s\n",
						   IMG_GetError());
				}

				// Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)

				{

					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
						   Mix_GetError());
				}

				// Initialize SDL_ttf
				if (TTF_Init() == -1)

				{

					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
						   TTF_GetError());
				}
			}
		}
	}

	AnChuot = Mix_LoadWAV("Sound/AnChuot.wav");
}

void KetThuc()
{

	Mix_FreeChunk(AnChuot);

	AnChuot = NULL;

	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(render);

	window = NULL;

	render = NULL;

	ChoiLai = false;

	IMG_Quit();

	Mix_Quit();

	TTF_Quit();

	SDL_Quit();
}

int main(int argc, char *argv[])
{

	init();

	while (1)

	{

		if (XuLiMenu())

		{

			Play();

			End();

			GiaiPhongBoNhoPlay();

			GiaiPhongBoNhoMenu();

			if (ChoiLai != true)
				break;
		}
	}

	KetThuc();
}
