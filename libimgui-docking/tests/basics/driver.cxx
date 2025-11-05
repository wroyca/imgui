#include <libimgui-docking/imgui.h>

#undef NDEBUG
#include <cassert>
#include <cstring>

int
main ()
{
  // Test context creation and destruction.
  //
  {
    ImGuiContext* ctx (ImGui::CreateContext ());
    assert (ctx != nullptr);

    ImGui::SetCurrentContext (ctx);
    assert (ImGui::GetCurrentContext () == ctx);

    ImGui::DestroyContext (ctx);
  }

  // Test basic state and configuration.
  //
  {
    ImGuiContext* ctx (ImGui::CreateContext ());
    ImGui::SetCurrentContext (ctx);

    ImGuiIO& io (ImGui::GetIO ());
    io.DisplaySize = ImVec2 (1920.0f, 1080.0f);
    assert (io.DisplaySize.x == 1920.0f && io.DisplaySize.y == 1080.0f);

    ImGuiStyle& style (ImGui::GetStyle ());
    style.Alpha = 0.5f;
    assert (style.Alpha == 0.5f);

    ImGui::DestroyContext (ctx);
  }

  // Test frame operations with font atlas.
  //
  {
    ImGuiContext* ctx (ImGui::CreateContext ());
    ImGui::SetCurrentContext (ctx);

    ImGuiIO& io (ImGui::GetIO ());
    io.DisplaySize = ImVec2 (800.0f, 600.0f);
    io.DeltaTime = 1.0f / 60.0f;

    // Build font atlas (required before NewFrame).
    //
    unsigned char* pixels (nullptr);
    int width (0), height (0);
    io.Fonts->GetTexDataAsRGBA32 (&pixels, &width, &height);
    assert (pixels != nullptr && width > 0 && height > 0);
    io.Fonts->TexID = static_cast<ImTextureID> (1); // dummy

    // Create a simple frame.
    //
    ImGui::NewFrame ();
    {
      ImGui::Begin ("Test Window");
      ImGui::Text ("Hello, ImGui!");

      float f (0.0f);
      ImGui::SliderFloat ("float", &f, 0.0f, 1.0f);

      bool checkbox (false);
      ImGui::Checkbox ("checkbox", &checkbox);

      ImGui::End ();
    }
    ImGui::Render ();

    ImDrawData* draw_data (ImGui::GetDrawData ());
    assert (draw_data != nullptr);

    ImGui::DestroyContext (ctx);
  }

  // Test version information.
  //
  {
    const char* version (ImGui::GetVersion ());
    assert (version != nullptr && strlen (version) > 0);
  }
}
