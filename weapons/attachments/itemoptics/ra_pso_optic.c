class RA_PSO_Optic extends ItemOptics 
{
    override void OnOpticEnter()
    {
        super.OnOpticEnter();
        HideSelection("hide");
    }
	
    override void OnOpticExit()
    {
        super.OnOpticExit();
        ShowSelection("hide");
    }
}