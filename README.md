# pylon_toolchain_windows
headers and libraries for various versions of Basler's Pylon SDK

# Instructions
1. Clone the repository to your PC.
2. Run the setEnvironmentRunAsAdmin.bat file to create system environment variables which your project will use to find each SDK's headers & libraries.
3. Open the toolchain_sample_project.sln in Visual Studio. This project contains configurations for building against individual pylon versions, or a batch build of many.

# Note
None of the pylon runtime files are included in this toolchain. To actually run your built application, you must have its targeted version of pylon installed on your system.
