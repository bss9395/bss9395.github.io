function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    // call default implementation to actually install HelloWorld.exe!
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@\\HelloWorld.exe", "@StartMenuDir@\\Hello World.lnk",
            "workingDirectory=@TargetDir@");
		
        component.addOperation("CreateShortcut", "@TargetDir@\\HelloWorld.exe", "@DesktopDir@\\Hello World.lnk",
            "workingDirectory=@TargetDir@");
    }
}
