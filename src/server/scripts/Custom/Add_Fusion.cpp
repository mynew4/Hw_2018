/////////////////////////////////////////////////////////////////////////////
//         			Developed by Zie For Thesatria.COm                     //
//                     Copyright (C) 2015 Zie                              //
//                          Thesatria.Com                                  //
/////////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"

class npc_fusion : public CreatureScript
{
public:
    npc_fusion() : CreatureScript("npc_fusion") { }
	
	uint32 SelectDPoints(Player* pPlayer)
	{
		QueryResult select = LoginDatabase.PQuery("SELECT dp FROM web_db.account_data WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());
		if (!select) // Just in case, but should not happen
		{
			pPlayer->CLOSE_GOSSIP_MENU();
			return 0;
		}

		Field* fields = select->Fetch();
		uint32 dp = fields[0].GetUInt32();

		return dp;
	}

    bool OnGossipHello(Player *player, Creature *_creature)
    {
        if (player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            _creature->MonsterWhisper("You are in combat!", player->GetGUID());
            return true;
        }
        else
        {			
            player->ADD_GOSSIP_ITEM( 4, "|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:24|tConvert My Vote item to Upgrade token"         , GOSSIP_SENDER_MAIN, 3); //Change the ID below
            //player->ADD_GOSSIP_ITEM( 4, "|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:24|tConvert 1000 Demon Soul to 100 Golden Pearl"    , GOSSIP_SENDER_MAIN, 4); //Change the ID below
            //player->ADD_GOSSIP_ITEM( 4, "|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:24|tConvert 1000 Golden Pearl to 100 Black Diamond" , GOSSIP_SENDER_MAIN, 5); //Change the stats below
            //player->ADD_GOSSIP_ITEM( 4, "|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:24|tConvert 1000 Black Diamond to 100 Magic Card"   , GOSSIP_SENDER_MAIN, 6); //Change the stats below
            //player->ADD_GOSSIP_ITEM( 4, "|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:24|tConvert 1000 Magic Card to 30 Star Coin"   			, GOSSIP_SENDER_MAIN, 7);
			//player->ADD_GOSSIP_ITEM( 4, "|cffADD8E6|TInterface\\icons\\Achievement_Dungeon_Icecrown_Frostmourne:24|tConvert 500 Star Coin to 1 Donation Points"   	, GOSSIP_SENDER_MAIN, 8);
			//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Return.", GOSSIP_SENDER_MAIN, 9999);
			player->PlayerTalkClass->SendGossipMenu(85006, _creature->GetGUID());
        }

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            player->PlayerTalkClass->ClearMenus();
            switch(uiAction)
            {
            case 3: 
                if (player->HasItemCount( 173408, 1, false ))  //Demon Head
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(173408, 1, true, false);
                    player->AddItem(27, 1);
                    _creature->MonsterWhisper("Your Vote item Successfully convert to upgrade token", player->GetGUID());
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    _creature->MonsterWhisper("You don't have vote item !!", player->GetGUID());
                    return false;
                }
                break;

            case 4: 
                if (player->HasItemCount( 320287, 1000, false ))  //demon soul
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(320287, 1000, true, false);
                    player->AddItem(320288, 100);
                    _creature->MonsterWhisper("Your DS was successfully converted to GP!", player->GetGUID());
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    _creature->MonsterWhisper("You don't have any Demon Soul !!", player->GetGUID());
                    return false;
                }
                break;
            case 5: //token-token
                if (player->HasItemCount( 320288, 1000, false )) //golden peral
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(320288, 1000, true, false);
                    player->AddItem(320289, 100);
                    _creature->MonsterWhisper("You exchanged successfully converted to BD!", player->GetGUID());
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    _creature->MonsterWhisper("You don't have any Golden Pearl !!.", player->GetGUID());
                    return false;
                }
                break;
			case 6: //black diamond
                if (player->HasItemCount( 320289, 1000, false ))
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(320289, 1000, true, false);
                    player->AddItem(320290, 100);
                    _creature->MonsterWhisper("You exchanged successfully converted to MC!", player->GetGUID());
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    _creature->MonsterWhisper("You don't have any Black Diamond !!.", player->GetGUID());
                    return false;
                }
                break;
				
			case 7: //magic card
                if (player->HasItemCount( 320290, 1000, false ))
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(320290, 1000, true, false);
                    player->AddItem(340006, 24);
                    _creature->MonsterWhisper("You exchanged successfully converted to SC!", player->GetGUID());
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    _creature->MonsterWhisper("You don't have any Magic Card !!.", player->GetGUID());
                    return false;
                }
                break;
				
			case 8: //SC
                if (player->HasItemCount( 340006, 500, false ))
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->DestroyItemCount(340006, 500, true, false);
                    LoginDatabase.PQuery("Update web_db.account_data Set dp = dp + 1 WHERE id = '%u'", player->GetSession()->GetAccountId());
                    _creature->MonsterWhisper("You exchanged successfully, now you got more 2 Donation point, Check your Points At menu!", player->GetGUID());
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    _creature->MonsterWhisper("You don't have any Magic Card !!.", player->GetGUID());
                    return false;
                }
                break;
				
			case 9999:
                player->PlayerTalkClass->ClearMenus();
                OnGossipHello(player, _creature);
                break;
            } 
        } 
        return true;
    } 
};

void AddSC_npc_fusion()
{
    new npc_fusion();
}