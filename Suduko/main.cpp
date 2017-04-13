#include "main.hpp"



int main(int, char**, HANDLE console)
{
	bool consoleOnly = false;
	int puzzle[9][9];
	int originalCpy[9][9];
	int output[9][9];                          
	int debug[9][9] =
	{
		{ 5,7,0, 0,8,0, 0,0,0 },
		{ 2,2,4, 0,0,0, 0,0,8 }, 
		{ 3,0,0, 9,0,2, 0,7,0 },

		{ 0,0,0, 0,9,0, 0,0,0 },
		{ 0,0,5, 0,2,0, 0,4,7 },
		{ 0,8,0, 0,0,0, 0,6,2 },

		{ 0,3,2, 5,0,6, 0,8,0 },
		{ 0,4,7, 0,0,3, 0,0,6 },
		{ 0,5,0, 2,0,0, 1,0,0 }
	};
	ZeroMemory(output, sizeof(int) * 81);
	ZeroMemory(puzzle, sizeof(int) * 81);
	ZeroMemory(originalCpy, sizeof(int) * 81);

	

	Solver* s = new Solver;
	if (GetAsyncKeyState(VK_SPACE))
	{
		memcpy(puzzle, debug, sizeof(puzzle));
	}



	WORD oldColor;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	oldColor = csbi.wAttributes;


	
	


	if(consoleOnly)
	{
		memcpy(originalCpy, puzzle, sizeof(puzzle));

		if (s->precheckInput(originalCpy))
		{
			std::cout << "Computing solution...";
			if (s->solve(originalCpy, output))
			{
				if (s->validateSolution(output))
				{
					system("cls");
					s->draw(output, originalCpy);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "\nSolution validated!";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), oldColor);
				}
			}
			else
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "\nUnable to generate solution. The puzzle is likely unsolvable via brute-force.";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), oldColor);
			}
		}
		else
		{
			Beep(600, 500);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "\nError: Input is in invalid; There is a duplicate number in a row/col/box.\n\n You may close this window...";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), oldColor);
			std::cin.get();
		}

		std::cin.get();
	}
	



	

	if (!consoleOnly)
	{
		FreeConsole();
		// Manually declaring every int used and initializing to zero. Use of arrays or vectors caused bugs.

		int a0, a1, a2, a3, a4, a5, a6, a7, a8,
			b0, b1, b2, b3, b4, b5, b6, b7, b8,
			c0, c1, c2, c3, c4, c5, c6, c7, c8,

			d0, d1, d2, d3, d4, d5, d6, d7, d8,
			e0, e1, e2, e3, e4, e5, e6, e7, e8,
			f0, f1, f2, f3, f4, f5, f6, f7, f8,

			g0, g1, g2, g3, g4, g5, g6, g7, g8,
			h0, h1, h2, h3, h4, h5, h6, h7, h8,
			i0, i1, i2, i3, i4, i5, i6, i7, i8;

		a0 = a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = 0;
		b0 = b1 = b2 = b3 = b4 = b5 = b6 = b7 = b8 = 0;
		c0 = c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = 0;
		d0 = d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = 0;
		e0 = e1 = e2 = e3 = e4 = e5 = e6 = e7 = e8 = 0;
		f0 = f1 = f2 = f3 = f4 = f5 = f6 = f7 = f8 = 0;
		g0 = g1 = g2 = g3 = g4 = g5 = g6 = g7 = g8 = 0;
		h0 = h1 = h2 = h3 = h4 = h5 = h6 = h7 = h8 = 0;
		i0 = i1 = i2 = i3 = i4 = i5 = i6 = i7 = i8 = 0;
		
		

		int Oa0, Oa1, Oa2, Oa3, Oa4, Oa5, Oa6, Oa7, Oa8,
			Ob0, Ob1, Ob2, Ob3, Ob4, Ob5, Ob6, Ob7, Ob8,
			Oc0, Oc1, Oc2, Oc3, Oc4, Oc5, Oc6, Oc7, Oc8,

			Od0, Od1, Od2, Od3, Od4, Od5, Od6, Od7, Od8,
			Oe0, Oe1, Oe2, Oe3, Oe4, Oe5, Oe6, Oe7, Oe8,
			Of0, Of1, Of2, Of3, Of4, Of5, Of6, Of7, Of8,

			Og0, Og1, Og2, Og3, Og4, Og5, Og6, Og7, Og8,
			Oh0, Oh1, Oh2, Oh3, Oh4, Oh5, Oh6, Oh7, Oh8,
			Oi0, Oi1, Oi2, Oi3, Oi4, Oi5, Oi6, Oi7, Oi8;

		Oa0 = Oa1 = Oa2 = Oa3 = Oa4 = Oa5 = Oa6 = Oa7 = Oa8 = 0;
		Ob0 = Ob1 = Ob2 = Ob3 = Ob4 = Ob5 = Ob6 = Ob7 = Ob8 = 0;
		Oc0 = Oc1 = Oc2 = Oc3 = Oc4 = Oc5 = Oc6 = Oc7 = Oc8 = 0;

		Od0 = Od1 = Od2 = Od3 = Od4 = Od5 = Od6 = Od7 = Od8 = 0;
		Oe0 = Oe1 = Oe2 = Oe3 = Oe4 = Oe5 = Oe6 = Oe7 = Oe8 = 0;
		Of0 = Of1 = Of2 = Of3 = Of4 = Of5 = Of6 = Of7 = Of8 = 0;

		Og0 = Og1 = Og2 = Og3 = Og4 = Og5 = Og6 = Og7 = Og8 = 0;
		Oh0 = Oh1 = Oh2 = Oh3 = Oh4 = Oh5 = Oh6 = Oh7 = Oh8 = 0;
		Oi0 = Oi1 = Oi2 = Oi3 = Oi4 = Oi5 = Oi6 = Oi7 = Oi8 = 0;
		

		// Create application window
		WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL, _T("SudukoGUI"), NULL };
		RegisterClassEx(&wc);
		HWND hwnd = CreateWindow(_T("SudukoGUI"), _T("Suduko Solver"), WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 100, 100, 1200, 650, NULL, NULL, wc.hInstance, NULL);

		// Initialize Direct3D
		LPDIRECT3D9 pD3D;
		if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		{
			UnregisterClass(_T("SudukoGUI"), wc.hInstance);
			return 0;
		}
		ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
		g_d3dpp.Windowed = TRUE;
		g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		g_d3dpp.EnableAutoDepthStencil = TRUE;
		g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		// Create the D3DDevice
		if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
		{
			pD3D->Release();
			UnregisterClass(_T("SudukoGUI"), wc.hInstance);
			return 0;
		}

		// Setup ImGui binding
		ImGui_ImplDX9_Init(hwnd, g_pd3dDevice);

		ImVec4 clear_col = ImColor(114, 144, 154);

		//Set theme
		ImGuiStyle* style = &ImGui::GetStyle();

		style->WindowPadding = ImVec2(10, 10);
		style->WindowRounding = 5.0f;
		style->FramePadding = ImVec2(5, 5);
		style->FrameRounding = 4.0f;
		style->ItemSpacing = ImVec2(12, 8);
		style->ItemInnerSpacing = ImVec2(8, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 15.0f;
		style->ScrollbarRounding = 9.0f;
		style->GrabMinSize = 5.0f;
		style->GrabRounding = 3.0f;
		style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
		style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.4f, 0.6f, 1.00f);
		style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.0f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
		style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, .50f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
		style->Colors[ImGuiCol_CheckMark] = ImVec4(0.60f, 0.21f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.4f, 0.2f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);


		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.18f, 0.24f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

		// Main loop
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				continue;
			}
			ImGui_ImplDX9_NewFrame();

			static bool open = true;

			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImVec2(1200, 650));

			//////

			ImGui::Begin("Suduko Solver", &open, ImVec2(0, 0), 0.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
			{
				ImGui::Columns(2);
				if (ImGui::CollapsingHeader("Input", NULL, true, true))
				{
					ImGui::Text("------------------------------------------------------------------");
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a0", &a0, 0, 0))
					{
						puzzle[0][0] = a0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a1", &a1, 0, 0))
					{
						puzzle[0][1] = a1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a2", &a2, 0, 0))
					{
						puzzle[0][2] = a2;
					} ImGui::SameLine(); ImGui::Text("|");


					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a3", &a3, 0, 0))
					{
						puzzle[0][3] = a3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a4", &a4, 0, 0))
					{
						puzzle[0][4] = a4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a5", &a5, 0, 0))
					{
						puzzle[0][5] = a5;
					} ImGui::SameLine(); ImGui::Text("|");

					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a6", &a6, 0, 0))
					{
						puzzle[0][6] = a6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a7", &a7, 0, 0))
					{
						puzzle[0][7] = a7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##a8", &a8, 0, 0))
					{
						puzzle[0][8] = a8;
					} ImGui::SameLine(); ImGui::Text("|");

					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b0", &b0, 0, 0))
					{
						puzzle[1][0] = b0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b1", &b1, 0, 0))
					{
						puzzle[1][1] = b1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b2", &b2, 0, 0))
					{
						puzzle[1][2] = b2;
					}ImGui::SameLine(); ImGui::Text("|");

					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b3", &b3, 0, 0))
					{
						puzzle[1][3] = b3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b4", &b4, 0, 0))
					{
						puzzle[1][4] = b4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b5", &b5, 0, 0))
					{
						puzzle[1][5] = b5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b6", &b6, 0, 0))
					{
						puzzle[1][6] = b6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b7", &b7, 0, 0))
					{
						puzzle[1][7] = b7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##b8", &b8, 0, 0))
					{
						puzzle[1][8] = b8;
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c0", &c0, 0, 0))
					{
						puzzle[2][0] = c0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c1", &c1, 0, 0))
					{
						puzzle[2][1] = c1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c2", &c2, 0, 0))
					{
						puzzle[2][2] = c2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c3", &c3, 0, 0))
					{
						puzzle[2][3] = c3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c4", &c4, 0, 0))
					{
						puzzle[2][4] = c4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c5", &c5, 0, 0))
					{
						puzzle[2][5] = c5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c6", &c6, 0, 0))
					{
						puzzle[2][6] = c6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c7", &c7, 0, 0))
					{
						puzzle[2][7] = c7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##c8", &c8, 0, 0))
					{
						puzzle[2][8] = c8;
					}ImGui::SameLine(); ImGui::Text("|");


					//// new line

					ImGui::Text("------------------------------------------------------------------");
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d0", &d0, 0, 0))
					{
						puzzle[3][0] = d0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d1", &d1, 0, 0))
					{
						puzzle[3][1] = d1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d2", &d2, 0, 0))
					{
						puzzle[3][2] = d2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d3", &d3, 0, 0))
					{
						puzzle[3][3] = d3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d4", &d4, 0, 0))
					{
						puzzle[3][4] = d4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d5", &d5, 0, 0))
					{
						puzzle[3][5] = d5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d6", &d6, 0, 0))
					{
						puzzle[3][6] = d6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d7", &d7, 0, 0))
					{
						puzzle[3][7] = d7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##d8", &d8, 0, 0))
					{
						puzzle[3][8] = d8;
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e0", &e0, 0, 0))
					{
						puzzle[4][0] = e0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e1", &e1, 0, 0))
					{
						puzzle[4][1] = e1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e2", &e2, 0, 0))
					{
						puzzle[4][2] = e2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e3", &e3, 0, 0))
					{
						puzzle[4][3] = e3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e4", &e4, 0, 0))
					{
						puzzle[4][4] = e4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e5", &e5, 0, 0))
					{
						puzzle[4][5] = e5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e6", &e6, 0, 0))
					{
						puzzle[4][6] = e6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e7", &e7, 0, 0))
					{
						puzzle[4][7] = e7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##e8", &e8, 0, 0))
					{
						puzzle[4][8] = e8;
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f0", &f0, 0, 0))
					{
						puzzle[5][0] = f0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f1", &f1, 0, 0))
					{
						puzzle[5][1] = f1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f2", &f2, 0, 0))
					{
						puzzle[5][2] = f2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f3", &f3, 0, 0))
					{
						puzzle[5][3] = f3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f4", &f4, 0, 0))
					{
						puzzle[5][4] = f4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f5", &f5, 0, 0))
					{
						puzzle[5][5] = f5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f6", &f6, 0, 0))
					{
						puzzle[5][6] = f6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f7", &f7, 0, 0))
					{
						puzzle[5][7] = f7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##f8", &f8, 0, 0))
					{
						puzzle[5][8] = f8;
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line
					ImGui::Text("------------------------------------------------------------------");
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g0", &g0, 0, 0))
					{
						puzzle[6][0] = g0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g1", &g1, 0, 0))
					{
						puzzle[6][1] = g1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g2", &g2, 0, 0))
					{
						puzzle[6][2] = g2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g3", &g3, 0, 0))
					{
						puzzle[6][3] = g3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g4", &g4, 0, 0))
					{
						puzzle[6][4] = g4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g5", &g5, 0, 0))
					{
						puzzle[6][5] = g5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g6", &g6, 0, 0))
					{
						puzzle[6][6] = g6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g7", &g7, 0, 0))
					{
						puzzle[6][7] = g7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##g8", &g8, 0, 0))
					{
						puzzle[6][8] = g8;
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h0", &h0, 0, 0))
					{
						puzzle[7][0] = h0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h1", &h1, 0, 0))
					{
						puzzle[7][1] = h1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h2", &h2, 0, 0))
					{
						puzzle[7][2] = h2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h3", &h3, 0, 0))
					{
						puzzle[7][3] = h3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h4", &h4, 0, 0))
					{
						puzzle[7][4] = h4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h5", &h5, 0, 0))
					{
						puzzle[7][5] = h5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h6", &h6, 0, 0))
					{
						puzzle[7][6] = h6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h7", &h7, 0, 0))
					{
						puzzle[7][7] = h7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##h8", &h8, 0, 0))
					{
						puzzle[7][8] = h8;
					}ImGui::SameLine(); ImGui::Text("|");


					//// new line
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i0", &i0, 0, 0))
					{
						puzzle[8][0] = i0;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i1", &i1, 0, 0))
					{
						puzzle[8][1] = i1;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i2", &i2, 0, 0))
					{
						puzzle[8][2] = i2;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i3", &i3, 0, 0))
					{
						puzzle[8][3] = i3;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i4", &i4, 0, 0))
					{
						puzzle[8][4] = i4;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i5", &i5, 0, 0))
					{
						puzzle[8][5] = i5;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i6", &i6, 0, 0))
					{
						puzzle[8][6] = i6;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i7", &i7, 0, 0))
					{
						puzzle[8][7] = i7;
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					if (ImGui::InputInt("##i8", &i8, 0, 0))
					{
						puzzle[8][8] = i8;
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::Text("------------------------------------------------------------------");
				}



				ImGui::NextColumn();
				if (ImGui::CollapsingHeader("Output", NULL, true, true))
				{
					ImGui::Text("------------------------------------------------------------------");
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa0", &Oa0, 0, 0);
					{
						Oa0 = output[0][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa1", &Oa1, 0, 0);
					{
						Oa1 = output[0][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa2", &Oa2, 0, 0);
					{
						Oa2 = output[0][2];
					} ImGui::SameLine(); ImGui::Text("|");


					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa3", &Oa3, 0, 0);
					{
						Oa3 = output[0][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa4", &Oa4, 0, 0);
					{
						Oa4 = output[0][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa5", &Oa5, 0, 0);
					{
						Oa5 = output[0][5];
					} ImGui::SameLine(); ImGui::Text("|");

					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa6", &Oa6, 0, 0);
					{
						Oa6 = output[0][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa7", &Oa7, 0, 0);
					{
						Oa7 = output[0][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oa8", &Oa8, 0, 0);
					{
						Oa8 = output[0][8];
					} ImGui::SameLine(); ImGui::Text("|");

					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob0", &Ob0, 0, 0);
					{
						Ob0 = output[1][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob1", &Ob1, 0, 0);
					{
						Ob1 = output[1][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob2", &Ob2, 0, 0);
					{
						Ob2 = output[1][2];
					}ImGui::SameLine(); ImGui::Text("|");

					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob3", &Ob3, 0, 0);
					{
						Ob3 = output[1][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob4", &Ob4, 0, 0);
					{
						Ob4 = output[1][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob5", &Ob5, 0, 0);
					{
						Ob5 = output[1][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob6", &Ob6, 0, 0);
					{
						Ob6 = output[1][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob7", &Ob7, 0, 0);
					{
						Ob7 = output[1][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Ob8", &Ob8, 0, 0);
					{
						Ob8 = output[1][8];
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc0", &Oc0, 0, 0);
					{
						Oc0 = output[2][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc1", &Oc1, 0, 0);
					{
						Oc1 = output[2][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc2", &Oc2, 0, 0);
					{
						Oc2 = output[2][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc3", &Oc3, 0, 0);
					{
						Oc3 = output[2][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc4", &Oc4, 0, 0);
					{
						Oc4 = output[2][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc5", &Oc5, 0, 0);
					{
						Oc5 = output[2][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc6", &Oc6, 0, 0);
					{
						Oc6 = output[2][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc7", &Oc7, 0, 0);
					{
						Oc7 = output[2][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oc8", &Oc8, 0, 0);
					{
						Oc8 = output[2][8];
					}ImGui::SameLine(); ImGui::Text("|");


					//// new line

					ImGui::Text("------------------------------------------------------------------");
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od0", &Od0, 0, 0);
					{
						Od0 = output[3][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od1", &Od1, 0, 0);
					{
						Od1 = output[3][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od2", &Od2, 0, 0);
					{
						Od2 = output[3][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od3", &Od3, 0, 0);
					{
						Od3 = output[3][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od4", &Od4, 0, 0);
					{
						Od4 = output[3][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od5", &Od5, 0, 0);
					{
						Od5 = output[3][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od6", &Od6, 0, 0);
					{
						Od6 = output[3][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od7", &Od7, 0, 0);
					{
						Od7 = output[3][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Od8", &Od8, 0, 0);
					{
						Od8 = output[3][8];
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe0", &Oe0, 0, 0);
					{
						Oe0 = output[4][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe1", &Oe1, 0, 0);
					{
						Oe1 = output[4][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe2", &Oe2, 0, 0);
					{
						Oe2 = output[4][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe3", &Oe3, 0, 0);
					{
						Oe3 = output[4][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe4", &Oe4, 0, 0);
					{
						Oe4 = output[4][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe5", &Oe5, 0, 0);
					{
						Oe5 = output[4][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe6", &Oe6, 0, 0);
					{
						Oe6 = output[4][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe7", &Oe7, 0, 0);
					{
						Oe7 = output[4][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oe8", &Oe8, 0, 0);
					{
						Oe8 = output[4][8];
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of0", &Of0, 0, 0);
					{
						Of0 = output[5][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of1", &Of1, 0, 0);
					{
						Of1 = output[5][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of2", &Of2, 0, 0);
					{
						Of2 = output[5][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of3", &Of3, 0, 0);
					{
						Of3 = output[5][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of4", &Of4, 0, 0);
					{
						Of4 = output[5][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of5", &Of5, 0, 0);
					{
						Of5 = output[5][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of6", &Of6, 0, 0);
					{
						Of6 = output[5][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of7", &Of7, 0, 0);
					{
						Of7 = output[5][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Of8", &Of8, 0, 0);
					{
						Of8 = output[5][8];
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line
					ImGui::Text("------------------------------------------------------------------");
					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og0", &Og0, 0, 0);
					{
						Og0 = output[6][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og1", &Og1, 0, 0);
					{
						Og1 = output[6][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og2", &Og2, 0, 0);
					{
						Og2 = output[6][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og3", &Og3, 0, 0);
					{
						Og3 = output[6][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og4", &Og4, 0, 0);
					{
						Og4 = output[6][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og5", &Og5, 0, 0);
					{
						Og5 = output[6][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og6", &Og6, 0, 0);
					{
						Og6 = output[6][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og7", &Og7, 0, 0);
					{
						Og7 = output[6][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Og8", &Og8, 0, 0);
					{
						Og8 = output[6][8];
					}ImGui::SameLine(); ImGui::Text("|");

					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh0", &Oh0, 0, 0);
					{
						Oh0 = output[7][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh1", &Oh1, 0, 0);
					{
						Oh1 = output[7][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh2", &Oh2, 0, 0);
					{
						Oh2 = output[7][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh3", &Oh3, 0, 0);
					{
						Oh3 = output[7][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh4", &Oh4, 0, 0);
					{
						Oh4 = output[7][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh5", &Oh5, 0, 0);
					{
						Oh5 = output[7][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh6", &Oh6, 0, 0);
					{
						Oh6 = output[7][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh7", &Oh7, 0, 0);
					{
						Oh7 = output[7][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oh8", &Oh8, 0, 0);
					{
						Oh8 = output[7][8];
					}ImGui::SameLine(); ImGui::Text("|");


					//// new line

					ImGui::Text("|"); ImGui::SameLine();
					ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi0", &Oi0, 0, 0);
					{
						Oi0 = output[8][0];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi1", &Oi1, 0, 0);
					{
						Oi1 = output[8][1];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi2", &Oi2, 0, 0);
					{
						Oi2 = output[8][2];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi3", &Oi3, 0, 0);
					{
						Oi3 = output[8][3];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi4", &Oi4, 0, 0);
					{
						Oi4 = output[8][4];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi5", &Oi5, 0, 0);
					{
						Oi5 = output[8][5];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi6", &Oi6, 0, 0);
					{
						Oi6 = output[8][6];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi7", &Oi7, 0, 0);
					{
						Oi7 = output[8][7];
					}
					ImGui::SameLine();  ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.0277777f);
					ImGui::InputInt("##Oi8", &Oi8, 0, 0);
					{
						Oi8 = output[8][8];
					}ImGui::SameLine(); ImGui::Text("|");
					ImGui::Text("------------------------------------------------------------------");
				}

				//Go Back to no columns
				ImGui::Columns(1);
				if (ImGui::Button("Solve", ImVec2(1165, 25)))
				{
					memcpy(originalCpy, puzzle, sizeof(puzzle));
					if (s->precheckInput(originalCpy))
					{
						if (!s->solve(originalCpy, output))
						{
							MessageBox(NULL, L"Error: This puzzle is impossible to solve via brute-force.", L"Puzzle Not Solvable", MB_ICONWARNING);
						}
					}
					else
					{
						MessageBox(NULL, L"Error: Input puzzle is in invalid. There is a duplicate number in a row/col/box.", L"Invalid Input", MB_ICONWARNING);
					}
					

				}
				if (ImGui::Button("Output to console", ImVec2(1165, 25)))
				{
					openConsole();
					s->draw(output, puzzle);
					FreeConsole();
				}

			}

			ImGui::End();

			////



			// Rendering
			g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
			g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
			g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
			D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_col.x*255.0f), (int)(clear_col.y*255.0f), (int)(clear_col.z*255.0f), (int)(clear_col.w*255.0f));
			g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
			if (g_pd3dDevice->BeginScene() >= 0)
			{
				ImGui::Render();
				g_pd3dDevice->EndScene();
			}
			g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
		}


		ImGui_ImplDX9_Shutdown();
		if (g_pd3dDevice) g_pd3dDevice->Release();
		if (pD3D) pD3D->Release();
		UnregisterClass(_T("SudukoGUI"), wc.hInstance);
	}


	return 0;
}




LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplDX9_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}