#pragma once
#include "solver.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imconfig.h"
#include <d3d9.h>
#include <dinput.h>
#include <tchar.h>
#include <process.h>
#include <xoleHlp.h>
#include <minwinbase.h>
#include "imgui/imgui_internal.h"
#include <iterator>
#pragma comment (lib, "d3d9.lib")
#include <thread>
#define DIRECTINPUT_VERSION 0x0800



static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;

extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

